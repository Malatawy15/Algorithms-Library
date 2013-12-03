//////////////////////////////////////////////////////////////////////////////////
// Naive SAT solver
// to solve simple SAT systems. Simple conflict recognition for backtracking.
// no complex heuristics.  Deterministically will exam the search space with 
// backtracking on a conflict.
//
// Incorporates data file verification into the problem
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

class Clause;

// Comment out the next line and uncomment the line after it to enable debug statements 
#define DEBUG( A ) 
//#define DEBUG( A ) A

// Values are values we assign to SAT variables
enum Values { FALSE, TRUE, UNDEFINED, INVALID };

// Table for computing AND operation on SAT values
Values AND[4][4] = { 
	{ FALSE, FALSE,     FALSE,     INVALID },
	{ FALSE, TRUE,      UNDEFINED, INVALID },
	{ FALSE, UNDEFINED, UNDEFINED, INVALID },
	{ INVALID, INVALID, INVALID,   INVALID } 
	};
// Table for computing OR operation on SAT values
Values OR[4][4] = { 
	{ FALSE,     TRUE,    UNDEFINED, INVALID },
	{ TRUE,      TRUE,    TRUE,      INVALID },
	{ UNDEFINED, TRUE,    UNDEFINED, INVALID },
	{ INVALID,   INVALID, INVALID,   INVALID }
	};

// Table for computing NOT operation on SAT valuse
Values NOT[4] = { TRUE, FALSE, UNDEFINED, INVALID };

class Literal
{
	public:
	   // Member Functions
		Literal() : val(INVALID) { }  // Initialize this variable to invalid, if referenced  in a formula, its 
		                              // initial value will then be changed to UNDEFINED. All variables must be used!
		Values operator=( Values ival ) { val = ival; return val; }
		void add_instance_ptr( int lit, Clause * pclause ) 
		{ 	if ( lit < 0 ) neg_instances.push_back(pclause); 
			else pos_instances.push_back(pclause);
		} 
		void clear_instances() { neg_instances.resize(0); pos_instances.resize(0); }
		
	    // Member Variables neg_instances and pos_instances could be used for heuristics, not used in this naive solver.
		vector<Clause *> neg_instances;
		vector<Clause *> pos_instances;
		Values val;
};

// The map is used to eliminate unused literal variables. Literals are re-mapped to the pos/neg integers as they are encountered.
map<int,int> vmap;

// the vector of Literals stores the values of the current variables
vector<Literal> vars;

// A clause is made from exactly 3 variables
class Clause
{
	public:
		Clause() : x1(0), x2(0), x3(0) {}
		Clause( int X1, int X2, int X3) : x1(X1), x2(X2), x3(X3) 
		{	vars[ abs(X1) ].add_instance_ptr( X1, this ); vars[ abs(X1) ] = UNDEFINED;
			vars[ abs(X2) ].add_instance_ptr( X2, this ); vars[ abs(X2) ] = UNDEFINED;
			vars[ abs(X3) ].add_instance_ptr( X3, this ); vars[ abs(X3) ] = UNDEFINED;
		}

		Values Eval( vector<Literal> & vars ) const
		{	
			//DEBUG(
			//	cout << "x1=" << x1 << " = " << (( x1 < 0 ) ? NOT[vars[-x1].val] : vars[x1].val) << "  ";
			//	cout << "x2=" << x2 << " = " << (( x2 < 0 ) ? NOT[vars[-x2].val] : vars[x2].val) << "  ";
			//	cout << "x3=" << x3 << " = " << (( x3 < 0 ) ? NOT[vars[-x3].val] : vars[x3].val) << endl;
			//)
			
			Values lit_1 = (( x1 < 0 ) ? NOT[vars[-x1].val] : vars[x1].val);
			Values lit_2 = (( x2 < 0 ) ? NOT[vars[-x2].val] : vars[x2].val);
			Values lit_3 = (( x3 < 0 ) ? NOT[vars[-x3].val] : vars[x3].val);
			return OR[ OR[lit_1][lit_2] ][ lit_3 ];
		}
		int x1, x2, x3;
};

// Sort all the clauses by the literals
class SortByLiterals
{
	public:
	bool operator() ( const Clause& a, const Clause& b )  const {
		if ( a.x1 < b.x1 ) return true;
		if ( !(a.x1 > b.x1) )
		{	if (a.x2 < b.x2) return true;
			if (!(a.x2 > b.x2) && (a.x3 < b.x3) ) return true;
		}
		return false;
	}

};

// All clauses are stored in a set 
set<Clause, SortByLiterals> clauses;

// Checks if a current set of clauses are satisfied
Values Check_if_SAT ( vector<Literal> & vars, set<Clause,SortByLiterals> & clauses, int depth )
{	// check if a all clauses evaluate to true 

	set<Clause,SortByLiterals>::iterator cit = clauses.begin();
	Values val = TRUE;
	while ( cit != clauses.end() )
	{	val = AND[ val][cit->Eval(vars)];
		if ( val == FALSE ) {
			return val;	// any false clause immediately indicates UNSAT can shortcut checking other clauses
		}
		cit++;
	}
	return val; // return the current status at this point either FALSE or TRUE
}

// NaiveSolve recursively searches the variable assignment space for a solution
Values NaiveSolve( vector<Literal> & vars, set<Clause,SortByLiterals> & clauses, int depth )
{   
	Values val;
	val = Check_if_SAT( vars, clauses, depth );
	if ( val == TRUE ) return TRUE;
	
	// Check if we have reached the end of the recursion
	if ( depth == vars.size() ) {	return val;	}

	// Choose next variable - currently a naive choice...
	vars[depth] = FALSE;
	val = NaiveSolve( vars, clauses, depth+1 );
	if ( val == TRUE ) return TRUE;  // SAT!
	
	vars[depth] = TRUE; 
	val = NaiveSolve( vars, clauses, depth+1 );
	if ( val == TRUE ) return TRUE; // SAT!
	
	// leaving this without finding anything, reset this variable as undefined.
	vars[depth] = UNDEFINED;
	
	return val;  
}

int main()
{
	int nvars, nclauses, c, cases;
	cin >> cases;
    DEBUG( cout << cases << endl; )	
	while ( cases --> 0 )
	{
		cin >> nvars >> nclauses;
		DEBUG( cout << nvars << " " << nclauses << endl; )
		if ( nvars < 3 ) {
			cout << "INVALID JUDGES INPUT FILE! nvars is " << nvars << endl;
			return 0;
		}
		if (nclauses < 1) {
			cout << "INVALID JUDGES INPUT FILE! nclauses is " << nclauses << endl;
			return 0;
		}

		int vid = 1; // variable id counter
		c = nclauses; 
		vmap.clear();
		vars.resize(0);
		
		vars.push_back(Literal()); // Need an extra var since we don't index off 0
		vars[0].val = INVALID;     // We don't use var 0! Mark it INVALID
	
		clauses.clear();
		//bool E_CLAUSE_ERROR = false;
		bool E_REPEATED_VARIABLE_IN_CLAUSE = false;
		bool E_NULL_VARIABLE = false;
		bool E_INVALID_VARIABLE = false;
		//bool E_NOT_ALL_VARIABLES_USED = false;

		while ( c --> 0 )
		{
			int x1, x2, x3, zero;
			cin >>  x1 >> x2 >> x3 >> zero;
			DEBUG( cout << x1 << " " << x2 << " " << x3 << " " << zero << endl; )
			if ( zero != 0 ) {
				cout << "INVALID JUDGES INPUT FILE! missing 0 terminator on clause line." << endl;
				return 0;
			}
			// Check for an invalid clause, watch for precedance of errors!
			//   o Null variables are not allowed.
			//   o The clause variable must be a valid variable i.e. ( -nvars <= x < 0 ) && ( 0 < x <= nvars )
			//   o Variables must not be repeated within a specific clause.
			// NOTE: Clauses may possibly be repeated in the input set, that's why we put them in a set so they only go in one time.
			if ( (abs(x1)==0)  || (abs(x2)==0)  || (abs(x3)==0) ) { E_NULL_VARIABLE = true; }
			if ( (abs(x1)>nvars) || (abs(x2)>nvars) || (abs(x3)>nvars) )   { E_INVALID_VARIABLE = true;  }
			if ( (abs(x1)==abs(x2)) || (abs(x1)==abs(x3)) || (abs(x2)==abs(x3)))  {	E_REPEATED_VARIABLE_IN_CLAUSE = true; }

			int vx1, vx2, vx3;
			map<int,int>::iterator imap;
			// Remap variables used in the clauses to numbered variables. This will avoid the trouble of unused variables in clauses.
			imap = vmap.find( abs(x1) ); if ( imap == vmap.end() ) {vmap[abs(x1)] = vx1 = vid; vars.push_back(Literal()); vid++;} else {vx1 = vmap[abs(x1)];}
			imap = vmap.find( abs(x2) ); if ( imap == vmap.end() ) {vmap[abs(x2)] = vx2 = vid; vars.push_back(Literal()); vid++;} else {vx2 = vmap[abs(x2)];}
			imap = vmap.find( abs(x3) ); if ( imap == vmap.end() ) {vmap[abs(x3)] = vx3 = vid; vars.push_back(Literal()); vid++;} else {vx3 = vmap[abs(x3)];}

			if ( !E_INVALID_VARIABLE && !E_NULL_VARIABLE && !E_REPEATED_VARIABLE_IN_CLAUSE ) 
			{
				clauses.insert( Clause( ((x1<0)?-vx1:vx1), ((x2<0)?-vx2:vx2), ((x3<0)?-vx3:vx3) ) );
			}
		}

		// If the clauses are all valid, check if all variables used at least one time. (Lowest precedence error)
		// if ( !E_INVALID_VARIABLE && !E_NULL_VARIABLE && !E_REPEATED_VARIABLE_IN_CLAUSE )
		//	for ( int i=1; i<=vars.size(); i++ )
		//		if ( vars[i].val == INVALID ) 
		//			E_NOT_ALL_VARIABLES_USED = true;
		
		// Check errors in order of priority, output highest priority error first
		if ( E_NULL_VARIABLE )                    cout << "INVALID: NULL RING" << endl; 
		else if ( E_INVALID_VARIABLE )            cout << "INVALID: RING MISSING" << endl;
		else if ( E_REPEATED_VARIABLE_IN_CLAUSE ) cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl; 
		// else if ( E_NOT_ALL_VARIABLES_USED )      cout << "INVALID: NOT ALL VARIABLES USED" << endl; 
		else {
			DEBUG( cout << "SIZE:" << vars.size() << endl; )
			Values val = NaiveSolve( vars, clauses, 1 );
			if ( val == FALSE ) 	cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!" << endl;
			else if ( val == TRUE )	
			{
				cout << "RUNES SATISFIED!" << endl;
					DEBUG( 
							vector<Literal>::iterator vit = vars.begin(); vit++;  // skip var[0], not used.
							for ( ; vit != vars.end(); vit++ )
								cout << "v[" << (vit-vars.begin()) << "]=" << (vit->val) << " ";
							cout << endl;
							set<Clause>::iterator sit = clauses.begin(); 
							for ( ; sit != clauses.end(); sit++ )
								cout << sit->x1 << " " << sit->x2 << " " << sit->x3 << " " << 0 << endl;
							
					)
			}
			else                    cout << "ERROR: INCORRECT VALUE RETURNED FROM SOLVER, SHOULD NOT HAPPEN" << endl;
		}
	}

	return 0;
}




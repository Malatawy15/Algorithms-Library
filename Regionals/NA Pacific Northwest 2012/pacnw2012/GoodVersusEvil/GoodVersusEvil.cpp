#include <iostream>
using namespace std ;
int main(int argc, char *argv[]) {
   int kases, g1, g2, g3, g4, g5, g6, e1, e2, e3, e4, e5, e6, e7 ;
   cin >> kases ;
   for (int kase=1; kase<=kases; kase++) {
      cin >> g1 >> g2 >> g3 >> g4 >> g5 >> g6 
          >> e1 >> e2 >> e3 >> e4 >> e5 >> e6 >> e7 ;
      int disc = g1 + 2 * g2 + 3 * g3 + 3 * g4 + 4 * g5 + 10 * g6 -
                 (e1 + 2 * e2 + 2 * e3 + 2 * e4 + 3 * e5 + 5 * e6 + 10 * e7) ;
      cout << "Battle " << kase << ": " ;
      if (disc > 0)
         cout << "Good triumphs over Evil" << endl ;
      else if (disc < 0)
         cout << "Evil eradicates all trace of Good" << endl ;
      else
         cout <<"No victor on this battle field" << endl ;
   }
}

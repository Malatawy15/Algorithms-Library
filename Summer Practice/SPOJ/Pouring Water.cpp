#include<stdio.h>
#include<queue>
#include<vector>
#include <set>

using namespace std;
#define Jars pair<int, pair<int, int> >
#define ac first
#define bc second.first
#define pos second.second
#define mp(a,b,c) make_pair(a, make_pair(b, c))

int a,b,c;

int gcd (int a, int b){
    if (a==0)
        return b;
    return gcd(b%a, a);
}
//set<int> sp;
set<pair<int, int> > sp1;
int bfs(){
    queue<Jars> q;
    q.push(mp(0,0,0));
    while (!q.empty()){
        Jars j = q.front();
        if (sp1.count(make_pair(j.ac, j.bc))!=0)
            continue;
      //  sp.insert(j.ac);
        //sp.insert(j.bc);
        //if (j.pos>20)
          //  break;
        sp1.insert(make_pair(j.ac, j.bc));
        q.pop();
        if (j.ac==c||j.bc==c)
            return j.pos;
        if (sp1.count(make_pair(j.ac,0))==0)
            q.push(mp(j.ac,0,j.pos+1));
        if (sp1.count(make_pair(0,j.bc))==0)
            q.push(mp(0,j.bc,j.pos+1));
        if (sp1.count(make_pair(a,j.bc))==0)
            q.push(mp(a,j.bc,j.pos+1));
        if (sp1.count(make_pair(j.ac,b))==0)
            q.push(mp(j.ac,b,j.pos+1));
        if (j.ac<b-j.bc){
            if (sp1.count(make_pair(0,j.bc+j.ac))==0)
                q.push(mp(0,j.bc+j.ac,j.pos+1));
        }
        else if (j.ac>b-j.bc){
            if (sp1.count(make_pair(j.ac-(b-j.bc),b))==0)
                q.push(mp(j.ac-(b-j.bc),b,j.pos+1));
        }
        if (j.bc<a-j.ac){
            if (sp1.count(make_pair(j.ac+j.bc,0))==0)
                q.push(mp(j.ac+j.bc,0,j.pos+1));
        }
        else if (j.bc>a-j.ac)
            if (sp1.count(make_pair(a,j.bc-(a-j.ac)))==0)
                q.push(mp(a,j.bc-(a-j.ac),j.pos+1));
    }
    return -1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        //sp.clear();
        sp1.clear();
        scanf("%d %d %d", &a, &b, &c);
        //if (!(c>a&&c>b)&&((a>b&&c%(a-b)==0)||(b>a&&c%(b-a)==0)||(a==b&&(c==a||c==0))))
        if(c > a && c > b) printf("-1\n");
		else if(!c) printf("0\n");
		else if(c == a || c == b) printf("1\n");
		else if(c % gcd(a, b)) printf("-1\n");
		else printf("%d\n", bfs());
        //bfs();
        //set<int>::iterator it;
        //for (it=sp.begin(); it!=sp.end(); ++it)
          //  printf("%d\n", *it);
        //set<pair<int, int> >::iterator it1;
        //for (it1=sp1.begin(); it1!=sp1.end(); ++it1)
          //  printf("%d %d\n", (*it1).first, (*it1).second);
    }
}

#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include <sstream>

using namespace std;

#define Config pair<string, pair<string, int> >
#define board first
#define moves second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

set<string> vis;
map <string ,Config> visited;
string ideal ="123456789";

string rotate_row( string s, int ind){
    string s1 = s;
    s1[3*ind]=s[3*ind+1];
    s1[3*ind+2]=s[3*ind];
    s1[3*ind+1]=s[3*ind+2];
    return s1;
}

string rotate_col(string s, int ind){
    string s1 = s;
    s1[ind]=s[6+ind];
    s1[3+ind]=s[ind];
    s1[6+ind]=s[3+ind];
    return s1;
}

void bfs(string s){
    queue<Config> q;
    q.push(mp(s,"",0));
    vis.clear();
    while(!q.empty()){
        Config c = q.front();
        q.pop();
        if (vis.count(c.board))
            continue;
        vis.insert(c.board);
        visited.insert(make_pair(c.board,c));
        //for (int i=0;i<3;i++)
        q.push(mp(rotate_row(c.board,0),"H1"+c.moves, c.cost+1));
        q.push(mp(rotate_row(c.board,1),"H2"+c.moves, c.cost+1));
        q.push(mp(rotate_row(c.board,2),"H3"+c.moves, c.cost+1));
        q.push(mp(rotate_col(c.board,0),"V1"+c.moves, c.cost+1));
        q.push(mp(rotate_col(c.board,1),"V2"+c.moves, c.cost+1));
        q.push(mp(rotate_col(c.board,2),"V3"+c.moves, c.cost+1));
        //for (int i=0;i<3;i++)
          //  q.push(mp(rotate_col(c.board,i),c.moves+"V"+(i+1), c.cost+1));
    }
}

int main(){
    int x;
    string s;
    bfs(ideal);
    //visited = vis;
    scanf("%d", &x);
    while(x){
        ostringstream oss;
        oss<<x;
        for (int i=0;i<8;i++){
            scanf("%d", &x);
            oss<<x;
        }
        s = oss.str();
        if (vis.count(s)>0){
            map<string, Config>::iterator it;
            it=visited.find(s);
            printf("%d %s\n", (it->second).cost, (it->second).moves.c_str());
        }
        else printf("Not solvable\n");
        scanf("%d", &x);
    }
}

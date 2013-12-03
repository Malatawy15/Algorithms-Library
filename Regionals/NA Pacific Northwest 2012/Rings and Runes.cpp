#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

using namespace std;

int V, N, M;
/*
vector<int>graph[50];
vector<int>graphT[50];
int vis[50];
int comp[50];
map<int, int> mp;

stack<int> st;

void dfs1(int node){
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i=0;i<graph[node].size();i++)
        dfs1(graph[node][i]);
    st.push(node);
}

void dfs2(int node, int scc){
    if (!vis[node]) return;
    vis[node] = 0;
    comp[node] = scc;
    for (int i=0;i<graphT[node].size();i++){
        dfs2(graphT[node][i], scc);
    }
}

void kosaraju(){
    st = stack<int>();
    memset(vis,0,sizeof vis);
    memset(comp,0,sizeof comp);
    for (int i=0;i<V;i++){
        if (!vis[V]) dfs1(i);
    }
    int scc = 1;
    while(!st.empty()){
        int ele = st.top();st.pop();
        if (!vis[ele]) continue;
        dfs2(ele, scc++);
    }
}
*/

set<vector<int> > exp;
set<vector<int> >::iterator it;


int check(int bit){
    for (it = exp.begin();it!=exp.end();++it){
        int i;
        for (i=0;i<3;i++){
            int cur = (*it)[i];
            if ((bit&(1<<(abs(cur)-1)))&&cur>0){
                break;
            }
            if ((!(bit&(1<<(abs(cur)-1)))&&cur<0))
                break;
        }
        if (i==3)
            return 0;
    }
    return 1;
}


void solve(){
    for (int bit=0;bit<(1<<N);bit++){
        if (check(bit)){
            printf("RUNES SATISFIED!\n");
            return;
        }
    }
    printf("RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n");
}


int main(){
    int t,a,b,c,d, nr, rm, rr;
    scanf("%d", &t);
    while(t--){
        nr = 0;
        rr = 0;
        rm = 0;
        exp.clear();
        scanf("%d %d", &N, &M);
        //V = 2*N;
        for (int i=0;i<M;i++){
            scanf("%d %d %d %d", &a,&b,&c,&d);
            if (a==0||b==0||c==0)
                nr = 1;
            if (a>N||a<-N||b>N||b<-N||c>N||c<-N)
                rm = 1;
            if (abs(a)==abs(b)||abs(a)==abs(c)||abs(b)==abs(c))
                rr = 1;
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort (v.begin(), v.end());
            exp.insert(v);
        }
        if (nr){
            printf("INVALID: NULL RING\n");
            continue;
        }
        if (rm){
            printf("INVALID: RING MISSING\n");
            continue;
        }
        if (rr){
            printf("INVALID: RUNE CONTAINS A REPEATED RING\n");
            continue;
        }
        solve();
    }
}

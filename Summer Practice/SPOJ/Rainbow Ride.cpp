#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Pair pair<int, int>

int N, C, NN;

int vis[1001];
int weights[1001];
int dp[1001][1001];

vector<int> graph[1001];

vector<Pair > objs;

Pair dfs(int node){
    if (vis[node])
        return Pair(0,0);
    vis[node] = 1;
    Pair p(1,weights[node]);
    for (int i=0;i<graph[node].size();i++){
    	Pair p1 = dfs(graph[node][i]);
        p.first += p1.first;
        p.second += p1.second;
    }
    return p;
}

int maximize(int n, int rem){
    if (rem<0)
        return -100000000;
    if (n==NN)
        return 0;
    if (rem==0)
        return 0;
    if (dp[n][rem]!=-1)
        return dp[n][rem];
    return dp[n][rem] = max(objs[n].first+maximize(n+1, rem-objs[n].second),maximize(n+1,rem));
}

int main(){
    int nn, nl;
    scanf("%d %d", &N, &C);
    while(!(!N&&!C)){
        for (int i=0;i<N;i++)
            scanf("%d", &weights[i]);
        for (int i=0;i<N;i++){
            scanf("%d", &nn);
            for (int j=0;j<nn;j++){
                scanf("%d", &nl);
                nl--;
                graph[i].push_back(nl);
                graph[nl].push_back(i);
            }
        }
        memset(vis, 0, sizeof vis);
        for (int i=0;i<N;i++){
            if (!vis[i]){
            	Pair p1 = dfs(i);
            	objs.push_back(p1);
            }
        }
        NN = objs.size();
        memset(dp, -1, sizeof dp);
        printf("%d\n", max(0, maximize(0,C)));
        for (int i=0;i<N;i++)
            graph[i].clear();
        objs.clear();
        scanf("%d %d", &N, &C);
    }
}

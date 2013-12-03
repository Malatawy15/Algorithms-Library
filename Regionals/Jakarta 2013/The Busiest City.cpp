#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Pair pair<int, int>

int N;
vector<Pair> graph[20010];
//int vis[20010];
int comp[20010][2];
int edges[20010][2];

int dfs(int node, int edg, int l, int par){
    comp[edg][l] = 1;
    for (int i=0;i<graph[node].size();i++)
        if (graph[node][i].first!=par)
            comp[edg][l] += dfs(graph[node][i].first,graph[node][i].second,graph[node][i].first<node?0:1,node);
    comp[edg][(l+1)%2] = N-comp[edg][l];
    return comp[edg][l];
}

int main(){
    int t, cn = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for (int i=1;i<=N;i++)
            graph[i].clear();
        for (int i=0;i<N-1;i++){
            scanf("%d %d", &edges[i][0], &edges[i][1]);
            if (edges[i][0]>edges[i][1])
                swap(edges[i][0],edges[i][1]);
            graph[edges[i][0]].push_back(Pair(edges[i][1],i));
            graph[edges[i][1]].push_back(Pair(edges[i][0],i));
        }
        dfs(edges[0][0],0,0,edges[0][1]);
        dfs(edges[0][1],0,1,edges[0][0]);
        int maxi = 0;
        for (int i=1;i<=N;i++){
            int n = N-1, sum = 0;
            for(int j=0;j<graph[i].size();j++){
                int v = graph[i][j].first, ind = graph[i][j].second;
                if (i<v){
                    n-=comp[ind][1];
                    sum+=n*(comp[ind][1]);
                }
                else {
                    n-=comp[ind][0];
                    sum+=n*(comp[ind][0]);
                }
            }
            maxi = max(maxi,sum);
            //printf("NODE %d: %d\n",i,sum);
        }
        printf("Case #%d: %d\n", cn++,maxi);
    }
}

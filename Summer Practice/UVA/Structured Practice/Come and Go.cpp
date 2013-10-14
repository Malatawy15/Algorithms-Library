#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N, M;
vector<int>graph[2001];
int vis[2001];

int dfs(int node){
    if (vis[node])
        return 0;
    vis[node] = 1;
    int sum = 1;
    for (int i=0;i<graph[node].size();i++)
        sum+=dfs(graph[node][i]);
    return sum;
}

int predicate(){
    for (int i=1;i<=N;i++){
        memset(vis,0,sizeof vis);
        if (dfs(i)!=N)
            return 0;
    }
    return 1;
}

int main(){
    int x,y,z;
    scanf("%d %d",&N,&M);
    while(!(!N&&!M)){
        for (int i=0;i<=N;i++)
            graph[i].clear();
        for (int i=0;i<M;i++){
            scanf("%d %d %d",&x,&y,&z);
            if (z>1)
                graph[x].push_back(y), graph[y].push_back(x);
            else graph[x].push_back(y);
        }
        printf("%d\n", predicate());
        scanf("%d %d",&N,&M);
    }
}

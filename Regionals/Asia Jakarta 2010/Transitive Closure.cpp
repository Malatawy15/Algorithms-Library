#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N, M;
vector<int> graph[2501];
int vis[2501];

int dfs(int node, int s){
    if (vis[node])
        return 0;
    vis[node] = 1;
    int sum = 1;
    for (int i=0;i<graph[node].size();i++)
        sum+=dfs(graph[node][i], s);
    return sum;
}

int count(){
    int sum = 0;
    for (int i=0;i<N;i++){
        memset(vis, 0, sizeof vis);
        sum+=dfs(i,i)-1;
    }
    return sum;
}

int main(){
    int t, x, y;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &M);
        for (int i=0;i<M;i++){
            scanf("%d %d", &x, &y);
            x--;y--;
            graph[x].push_back(y);
        }
        printf("%d\n", count());
        for (int i=0;i<N;i++)
            graph[i].clear();
    }
}

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, total = 0;
vector<int> graph[10010];
int vis[10010];

int dfs(int n){
    if (vis[n])
        return 0;
    vis[n] = 1;
    if (!graph[n].size()){
        total++;
        return 1;
    }
    int cur = 0;
    for (int i=0;i<graph[n].size();i++){
        if (!vis[graph[n][i]]){
            cur+=dfs(graph[n][i]);
            cur++;
        }
    }
    cur++;
    total+=cur;
    return cur;
}

int main(){
    int t,x,y;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        memset(vis, 0, sizeof vis);
        total = 0;
        for (int i=0;i<N-1;i++){
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        dfs(0);
        printf("%d\n", total);
        for (int i=0;i<N;i++){
            graph[i].clear();
        }
    }
}

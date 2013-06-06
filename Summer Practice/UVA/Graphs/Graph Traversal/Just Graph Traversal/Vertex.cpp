#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

vector<int> graph [101];
int vis[101];

int N;

void dfs (int node){
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i =0;i<graph[node].size();i++)
        dfs(graph[node][i]);
}

void find_unconnected(int node){
    memset(vis, 0, sizeof vis);
    int sum = 0;
    for (int i =0;i<graph[node].size();i++)
        dfs(graph[node][i]);
    for (int i=0;i<N;i++)
        if (!vis[i])
            sum++;
    printf("%d", sum);
    for (int i=0;i<N;i++)
        if (!vis[i])
            printf(" %d", i+1);
    printf("\n");
}

int main(){
    scanf("%d", &N);
    int s, v;
    while (N){
        for (int i =0;i<N;i++){
            graph[i].clear();
        }
        scanf("%d", &s);
        while (s){
            s--;
            scanf("%d", &v);
            while (v){
                v--;
                graph[s].push_back(v);
                scanf("%d", &v);
            }
            scanf("%d", &s);
        }
        scanf("%d", &s);
        for (int i =0;i<s;i++){
            scanf("%d", &v);
            v--;
            find_unconnected(v);
        }
        scanf("%d", &N);
    }
}

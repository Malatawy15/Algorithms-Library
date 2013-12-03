#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int R, C, Q;
vector<int> graph[10003];
int vis [10003];
/*
void dfs(int node, int scc){
    if (vis[node])
        return;
    vis[node] = scc;
    for (int i=0;i<graph[node].size();i++){
        dfs(graph[node][i], scc);
    }
}
*/
int dfs(int node, int y){
    if (vis[node]){
        if (node==y)
            return 0;
        else return 2;
    }
    vis[node] = 1;
    if (node==y)
        return 1;
    int xx = 2;
    for (int i=0;i<graph[node].size();i++){
        int x = dfs(graph[node][i],y);
        if (!x)
            return 0;
        else if (x==1)
            xx = 1;
    }
    return xx;
}

/*
void scc(){
    memset(vis,0,sizeof vis);
    int sc = 1;
    for (int i=1;i<=R;i++)
        if (!vis[i])
            dfs(i,sc++);
}
*/
int main(){
    int x, y;
    scanf("%d %d %d",&R,&C,&Q);
    while(!(!R&&!C&&!Q)){
        for (int i=1;i<=R;i++)
            graph[i].clear();
        for (int i=0;i<C;i++){
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
//        scc();
        for (int i=0;i<Q;i++){
            memset(vis,0,sizeof vis);
            scanf("%d %d", &x, &y);
            if (dfs(x,y)==1)
                printf("Y\n");
            else printf("N\n");
        }
        printf("-\n");
        scanf("%d %d %d",&R,&C,&Q);
    }
}

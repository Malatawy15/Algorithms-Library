#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int arr[50010];
int vis[50010];
int ind[50010];
int hp[50010];

int dfs(int node){
    if (ind[node])
        return 0;
    if (vis[node])
        return vis[node];
    ind [node] = 1;
    vis[node] = 1+dfs(arr[node]);
    ind[node] = 0;
    return vis[node];
}

int main(){
    int t, N,u,v;
    scanf("%d", &t);
    for (int k=1;k<=t;k++){
        memset(hp,0,sizeof hp);
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%d %d", &u,&v);
            arr[u] = v;
            hp[v] = 1;
        }
        int maxi = -1, maxI;
        memset(vis,0,sizeof vis);
        memset(ind,0,sizeof ind);
        for (int i=1;i<=N;i++)
        if (!hp[i]){
            int x = dfs(i);
                if (x>maxi)
                    maxi = x, maxI = i;
        }
        for (int i=1;i<=N;i++)
            if (!vis[i]){
                int x = dfs(i);
                if (x>maxi)
                    maxi = x, maxI = i;
            }
            else {
                int x = vis[i];
                if (x>maxi)
                    maxi = x, maxI = i;
            }
        printf("Case %d: %d\n",k,maxI);
    }
}

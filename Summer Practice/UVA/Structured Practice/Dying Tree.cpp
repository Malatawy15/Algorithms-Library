#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define Pair pair<int, int>
#define X first
#define Y second
#define EPS (1e-9)
int N, M, K, D;

vector<Pair>coords[200];
int vis[200];
vector<int> graph[200];


int dfs(int node){
    if (node<M)
        return 1;
    if (vis[node])
        return 0;
    vis[node] = 1;
    for (int i=0;i<graph[node].size();i++)
        if (dfs(graph[node][i]))
            return 1;
    return 0;
}

int main(){
    int t,x,y,z;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d",&N,&M,&K,&D);
        for (int i=0;i<=N+M;i++)
            graph[i].clear(), coords[i].clear();
        for (int i=0;i<M;i++){
            scanf("%d %d",&x,&y); coords[i].push_back(Pair(x,y));}
        for (int i=0;i<N;i++){
            int p = M+i, f = 0;
            scanf("%d",&z);
            for (int k=0;k<z;k++){
                scanf("%d %d",&x,&y); coords[p].push_back(Pair(x,y));}
            for (int j=0;j<p;j++){
                f = 0;
                for (int a=0;a<coords[p].size();a++){
                    for (int b=0;b<coords[j].size();b++){
                        double dis = hypot(abs(coords[p][a].X-coords[j][b].X),abs(coords[p][a].Y-coords[j][b].Y));
                        if (dis<=(j<M?D:K)){
                            graph[p].push_back(j);
                            graph[j].push_back(p);
                            f = 1;
                            break;
                        }
                    }
                    if (f)
                        break;
                }
            }
        }
        memset(vis,0,sizeof vis);
        if (dfs(M))
            printf("Tree can be saved :)\n");
        else printf("Tree can't be saved :(\n");
    }
}

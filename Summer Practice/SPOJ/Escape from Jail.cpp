#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Node pair<int, int>
#define id first
#define cost second

int N,K,M;
int doors[100010];
int vis[100010];
vector<int> maze[100010];


int bfs(){
    queue<int>q;
    int num=0;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        num++;
        int n = q.front();
        q.pop();
        if (n==N)
            return 1;
        if (num>2*N)
            return 0;
        if (doors[n]){
            if (!vis[doors[n]]){
                q.push(n);
                continue;
            }
        }
        num = 0;
        for (int i=0;i<maze[n].size();i++){
            if (!vis[maze[n][i]]){
                vis[maze[n][i]] = 1;
                q.push(maze[n][i]);
            }
        }
    }
    return 0;
}


int main(){
    scanf("%d %d %d",&N,&K,&M);
    int x,y;
    while(!(N==-1&&K==-1&&M==-1)){
        memset(doors,0,sizeof doors);
        memset(vis,0,sizeof vis);
        for (int i=0;i<K;i++){
            scanf("%d %d",&x,&y);
            doors[y] = x;
        }
        for (int i=0;i<M;i++){
            scanf("%d %d",&x,&y);
            maze[x].push_back(y);
            maze[y].push_back(x);
        }
        if (bfs())
            printf("Y\n");
        else printf("N\n");
        for (int i=0;i<=N;i++)
            maze[i].clear();
        scanf("%d %d %d",&N,&K,&M);
    }
}

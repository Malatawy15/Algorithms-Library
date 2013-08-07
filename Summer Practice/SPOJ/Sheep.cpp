#include<stdio.h>
#include<string.h>

using namespace std;

int N, M;
char grid[260][260];
int vis[260][260];
int curW, curS;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y){
    if (vis[x][y]||grid[x][y]=='#')
        return;
    vis[x][y] = 1;
    if (grid[x][y]=='k')
        curS++;
    else if (grid[x][y]=='v')
        curW++;
    for (int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<N&&ny<M&&!vis[nx][ny]&&grid[nx][ny]!='#')
            dfs(nx, ny);
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for (int i=0;i<N;i++)
        scanf("%s",grid[i]);
    memset(vis,0,sizeof vis);
    int totW = 0, totS = 0;
    for (int i=0;i<N;i++)
        if (!vis[i][0]&&grid[i][0]!='#'){
            curW = 0;
            curS = 0;
            dfs(i,0);
            totW+=curW;
            totS+=curS;
        }
    for (int i=0;i<N;i++)
        if (!vis[i][M-1]&&grid[i][M-1]!='#'){
            curW = 0;
            curS = 0;
            dfs(i,M-1);
            totW+=curW;
            totS+=curS;
        }
    for (int i=0;i<M;i++)
        if (!vis[0][i]&&grid[0][i]!='#'){
            curW = 0;
            curS = 0;
            dfs(0,i);
            totW+=curW;
            totS+=curS;
        }
    for (int i=0;i<M;i++)
        if (!vis[N-1][i]&&grid[N-1][i]!='#'){
            curW = 0;
            curS = 0;
            dfs(N-1,i);
            totW+=curW;
            totS+=curS;
        }
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            if (!vis[i][j]&&grid[i][j]!='#'){
                curW = 0;
                curS = 0;
                dfs(i,j);
                if (curS>curW){
                    totS+=curS;
                }
                else{
                    totW+=curW;
                }
            }
    printf("%d %d\n",totS, totW);
}

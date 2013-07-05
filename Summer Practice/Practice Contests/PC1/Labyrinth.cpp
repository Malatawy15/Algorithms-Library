#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

#define Point pair<int, int>

char lab[1010][1010];
int vis[1010][1010];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int maxD, maxNx, maxNy, R, C;

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

void dfs(int x, int y, int cost){
    if (vis[x][y]||lab[x][y]=='#'||!inside_grid(x,y))
        return;
    if (cost>maxD){
        maxD = cost;
        maxNx = x;
        maxNy = y;
    }
    vis[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (inside_grid(nx,ny))
            dfs(nx,ny,cost+1);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &C, &R);
        for (int i=0;i<R;i++)
            scanf("%s",lab[i]);
        int f = 0;
        memset(vis, 0, sizeof vis);
        maxD = -1;
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++)
                if (lab[i][j]=='.'){
                    dfs(i,j,0);
                    f = 1;
                    break;
                }
            if (f)
                break;
        }
        if (maxD==-1){
            printf("Maximum rope length is %d.\n",0);
            continue;
        }
        memset(vis, 0, sizeof vis);
        maxD = 0;
        dfs(maxNx, maxNy, 0);
        printf("Maximum rope length is %d.\n", maxD);
    }
}

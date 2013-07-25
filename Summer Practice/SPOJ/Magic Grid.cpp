#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int R, C, cn;
int dp[501][501];
int vis[501][501];
int grid[501][501];

int maximize(int x, int y){
    if (x==R-1&&y==C-1)
        return grid[x][y]>=0?0:abs(grid[x][y]);
    if (vis[x][y]==cn)
        return dp[x][y];
    vis[x][y] = cn;
    dp[x][y] = 1000000000;
    if (x!=R-1)
        dp[x][y] = min(dp[x][y], maximize(x+1, y));
    if (y!=C-1)
        dp[x][y] = min(dp[x][y], maximize(x, y+1));
    if (grid[x][y]>=0){
        if(dp[x][y]==0)
            return dp[x][y] = 0;
        else if (grid[x][y]>dp[x][y])
            return dp[x][y] = 0;
        else return dp[x][y] = dp[x][y]-grid[x][y];
    }
    else{
        if (dp[x][y]==0)
            return dp[x][y] = abs(grid[x][y]);
        else return dp[x][y] = dp[x][y] + abs(grid[x][y]);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for (cn = 1;cn<=t;cn++){
        scanf("%d %d", &R, &C);
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++)
                scanf("%d", &grid[i][j]);
        printf("%d\n", maximize(0,0)+1);
    }
}

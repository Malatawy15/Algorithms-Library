#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int dp[30][30];
int vals[30][30];
int N, M;

int minimize(int x, int y){
    if (x==N-1&&y==M-1)
        return vals[x][y];
    if (dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y] = vals[x][y];
    if (x==N-1)
        return dp[x][y]+=minimize(x,y+1);
    if (y==M-1)
        return dp[x][y]+=minimize(x+1,y);
    return dp[x][y]+=min(minimize(x+1,y), minimize(x,y+1));
}

int main(){
    scanf("%d %d",&N,&M);
    int x,y;
    scanf("%d %d",&x,&y);
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            scanf("%d",&vals[i][j]);
    memset(dp,-1,sizeof dp);
    int mini = minimize(x-1,y-1);
    mini = vals[x-1][y-1]*2-mini;
    if (mini>=0)
        printf("Y %d\n",mini);
    else printf("N\n");
}

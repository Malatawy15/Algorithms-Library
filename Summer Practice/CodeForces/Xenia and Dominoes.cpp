#include <stdio.h>
#include <string.h>

using namespace std;

const int MOD = 1000000007;

int W;

char grid[3][10001];
int dp[10001][20][20];

int count(int c, int b1, int b2){
    if (grid[0][c]=='X'||grid[0][c]=='O')
        b1|=(1);
    if (grid[1][c]=='X'||grid[1][c]=='O')
        b1|=(1<<1);
    if (grid[2][c]=='X'||grid[2][c]=='O')
        b1|=(1<<2);
    if (c==0)
        if (b1==1||b1==7||b1==4)
            return 1;
        else return 0;
    if ((b2&1)!=0&&(grid[0][c-1]=='X'||grid[0][c-1]=='O'))
        return 0;
    if ((b2&(1<<1))!=0&&(grid[1][c-1]=='X'||grid[1][c-1]=='O'))
        return 0;
    if ((b2&(1<<2))!=0&&(grid[2][c-1]=='X'||grid[2][c-1]=='O'))
        return 0;
    if (dp[c][b1][b2]!=-1)
        return dp[c][b1][b2];
    dp[c][b1][b2] = 0;
    if (b1==7)
        return dp[c][b1][b2] = count(c-1,b2,0);
    int pos;
    for (pos = 0;pos<3;pos++)
        if ((b1&(1<<pos))==0)
            break;
    if ((b2&(1<<pos))==0)
        dp[c][b1][b2] = (dp[c][b1][b2]+count(c,(b1|(1<<pos)),(b2|(1<<pos))))%MOD;
    if (pos<2&&(b1&(1<<(pos+1)))==0)
        dp[c][b1][b2] = (dp[c][b1][b2]+count(c,(b1|(1<<pos)|(1<<pos+1)),b2))%MOD;
    return dp[c][b1][b2]%MOD;
}

int main(){
    scanf("%d", &W);
    memset(dp,-1,sizeof dp);
    for (int i=0;i<3;i++)
        scanf("%s", grid[i]);
    printf("%d\n",count(W-1,0,0));
}

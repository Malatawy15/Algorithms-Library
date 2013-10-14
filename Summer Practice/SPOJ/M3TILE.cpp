#include <stdio.h>
#include <string.h>

using namespace std;

int W;

int dp[50][20][20];

int count(int c, int b1, int b2){
    if (c==0)
        if (b1==1||b1==7||b1==4)
            return 1;
        else return 0;
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
        dp[c][b1][b2]+=count(c,(b1|(1<<pos)),(b2|(1<<pos)));
    if (pos<2&&(b1&(1<<(pos+1)))==0)
        dp[c][b1][b2]+=count(c,(b1|(1<<pos)|(1<<pos+1)),b2);
    return dp[c][b1][b2];
}

int main(){
    scanf("%d", &W);
    memset(dp,-1,sizeof dp);
    while(W!=-1){
        if (W)
            printf("%d\n",count(W-1,0,0));
        else printf("1\n");
        scanf("%d", &W);
    }
}

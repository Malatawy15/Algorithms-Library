#include <stdio.h>
#include <string.h>

using namespace std;

int W;

int dp[50][20][20];

int count(int c, int b1, int b2){
    //printf("%d %d %d\n",c,b1,b2);
    if (c==0)
        if (b1==0||b1==15||b1==3||b1==12||b1==9)
            return 1;
        else return 0;
    if (dp[c][b1][b2]!=-1)
        return dp[c][b1][b2];
    dp[c][b1][b2] = 0;
    if (b1==15)
        return dp[c][b1][b2] = count(c-1,b2,0);
    int pos;
    for (pos = 0;pos<4;pos++)
        if ((b1&(1<<pos))==0)
            break;
    if ((b2&(1<<pos))==0)
        dp[c][b1][b2]+=count(c,(b1|(1<<pos)),(b2|(1<<pos)));
    if (pos<3&&(b1&(1<<(pos+1)))==0)
        dp[c][b1][b2]+=count(c,(b1|(1<<pos)|(1<<pos+1)),b2);
    return dp[c][b1][b2];
}

int main(){
    int t;
    scanf("%d", &t);
    memset(dp,-1,sizeof dp);
    for (int i=1;i<=t;i++){
        scanf("%d", &W);
        printf("%d %d\n",i,count(W-1,0,0));
    }
}

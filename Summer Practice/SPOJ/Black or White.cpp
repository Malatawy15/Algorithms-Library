#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
#define INF 1000000000

int N;
int dp[202][202][202];
int seq[202];

int minimize(int n, int lb, int lw){
    if (n>N)
        return 0;
    if (dp[n][lb][lw]!=-1)
        return dp[n][lb][lw];
    dp[n][lb][lw] = INF;
    if ((lb==0||seq[n]>seq[lb])&&(lw==0||seq[n]<seq[lw]))
        return dp[n][lb][lw] = min(minimize(n+1,lb,n),min(minimize(n+1,n,lw),1+minimize(n+1,lb,lw)));
    else if (lb==0||seq[n]>seq[lb])
        return dp[n][lb][lw] = min(minimize(n+1,n,lw),1+minimize(n+1,lb,lw));
    else if (lw==0||seq[n]<seq[lw])
        return dp[n][lb][lw] = min(minimize(n+1,lb,n),1+minimize(n+1,lb,lw));
    else return dp[n][lb][lw] = 1+minimize(n+1,lb,lw);
}

int main(){
    scanf("%d", &N);
    while(N>-1){
        for (int i=1;i<=N;i++)
            scanf("%d",&seq[i]);
        memset(dp,-1,sizeof dp);
        printf("%d\n",minimize(1,0,0));
        scanf("%d", &N);
    }
}

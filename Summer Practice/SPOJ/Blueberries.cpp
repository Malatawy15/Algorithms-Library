#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N, K;
int vals[1001];
int dp[1001][1001];

int maximize(int n, int msf){
    //printf("%d %d\n",n,msf);
    if (n>=N)
        return msf;
    if(dp[n][msf]!=-1)
        return dp[n][msf];
    if (msf==K)
        return msf;
    dp[n][msf] = 0;
    if (vals[n]+msf<=K)
        dp[n][msf] = max(maximize(n+2, msf+vals[n]),maximize(n+1, msf));
    else dp[n][msf] = maximize(n+1, msf);
    return dp[n][msf];
}

int main(){
    int t;
    scanf("%d", &t);
    for (int k=1;k<=t;k++){
        scanf("%d %d", &N, &K);
        memset(dp, -1, sizeof dp);
        for (int i=0;i<N;i++)
            scanf("%d", &vals[i]);
        printf("Scenario #%d: %d\n", k, maximize(0, 0));
    }
}

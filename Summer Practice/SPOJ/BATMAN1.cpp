#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N, M, K;

int batches[21];
int costs[21][21];
int pows[21][21];
int dp[21][21][1001];

int maximize(int n, int m, int rem){
    if (n==N)
        return 0;
    if (rem==0)
        return 0;
    if (dp[n][m][rem]!=-1)
        return dp[n][m][rem];
    dp[n][m][rem] = 0;
    for (int i=n+1;i<N;i++)
        if (batches[i]<=rem)
            dp[n][m][rem] = max(dp[n][m][rem], maximize(i,0,rem-batches[i]));
    for (int i=m;i<M;i++)
        if (rem>=costs[n][i])
            dp[n][m][rem] = max(dp[n][m][rem], pows[n][i]+maximize(n,i,rem-costs[n][i]));
    return dp[n][m][rem];
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d",&N,&M,&K);
        for (int i=0;i<N;i++)
            scanf("%d", &batches[i]);
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                scanf("%d", &costs[i][j]);
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                scanf("%d", &pows[i][j]);
        memset(dp,-1,sizeof dp);
        int maxi = 0;
        for (int i=0;i<N;i++){
            maxi = max(maxi, maximize(i,0,K-batches[i]));
        }
        printf("%d\n", maxi);
    }
}

#include<stdio.h>
#include<string.h>

using namespace std;

int N;
long long dp[70][11];

long long count(int n, int d){
    if (d>9)
        return 0;
    if (n==N)
        return 1LL;
    if (dp[n][d]!=-1)
        return dp[n][d];
    dp[n][d] = 0LL;
    return dp[n][d] = count(n+1,d)+count(n,d+1);
}

int main(){
    int t, cn;
    scanf("%d", &t);
    while(t--){
        memset(dp,-1,sizeof dp);
        scanf("%d %d", &cn, &N);
        printf("%d %lld\n",cn,count(0,0));
    }
}

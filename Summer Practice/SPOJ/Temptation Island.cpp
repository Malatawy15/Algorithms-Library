#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define mod(a,b) ((a+b)%b)

int N, K,a,b;
long long dp[51][51];

long long count(int n, int k){
    n = mod(n,N);
    if (k==K)
        if (n==b)
            return 1L;
        else return 0L;
    if (dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k] = 0L;
    dp[n][k] = count(n+1,k+1)+count(n-1,k+1);
    return dp[n][k];
}

int main(){
    scanf("%d %d", &N, &K);
    while(!(N==-1&&K==-1)){
        scanf("%d %d", &a, &b);
        a--;b--;
        memset(dp,-1,sizeof dp);
        printf("%lld\n", count(a,0));
        scanf("%d %d", &N, &K);
    }
}

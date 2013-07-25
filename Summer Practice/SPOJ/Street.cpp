#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N, K, T;
int dp[501][501];
int vals[501];

int maximize(int n, int k){
    if (n==N||k==K)
        return 0;
    if (dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k] = 0;
    dp[n][k] = maximize(n+1,k);
    int minH = 1000000000;
    for (int i=0;i<=T&&i+n<N;i++){
        minH = min(minH, vals[n+i]);
        dp[n][k] = max(dp[n][k], minH*(i+1)+maximize(n+i+1,k+1));
    }
    return dp[n][k];
}

int main(){
    scanf("%d %d %d", &N, &K, &T);
    for (int i=0;i<N;i++)
        scanf("%d", &vals[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", maximize(0, 0));
}

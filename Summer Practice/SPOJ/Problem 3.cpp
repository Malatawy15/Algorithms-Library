#include<stdio.h>
#include<string.h>

using namespace std;

int N;
long long dp[12][12];

long long recur(int lc, int len){
    if (len==N-1)
        return 1LL;
    if (dp[lc][len]!=-1)
        return dp[lc][len];
    dp[lc][len] = 0LL;
    for (int i=0;i<lc;i++)
        dp[lc][len]+=recur(lc, len+1);
    dp[lc][len]+=recur(lc+1, len+1);
    return dp[lc][len];
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(dp,-1, sizeof dp);
        scanf("%d", &N);
        printf("%lld\n", recur(1,0));
    }
}

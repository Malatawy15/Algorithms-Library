#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

long long dp[100010];
long long vals[100010];

int main(){
    int t, N;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for (int i=0;i<N;i++)
            scanf("%lld",&vals[i]);
        dp[N] = 0LL;
        dp[N+1] = 0LL;
        dp[N+2] = 0LL;
        dp[N+3] = 0LL;
        dp[N+4] = 0LL;
        dp[N+5] = 0LL;
        dp[N+6] = 0LL;
        vals[N] = 0LL;
        vals[N+1] = 0LL;
        vals[N+2] = 0LL;
        vals[N+3] = 0LL;
        vals[N+4] = 0LL;
        vals[N+5] = 0LL;
        vals[N+6] = 0LL;
        for (int i=N-1;i>=0;i--){
            dp[i] = 0LL;
            dp[i] = vals[i]+dp[i+2];
            if (i+1<N)
                dp[i] = max(dp[i], vals[i]+vals[i+1]+dp[i+4]);
            if (i+2<N)
                dp[i] = max(dp[i], vals[i]+vals[i+1]+vals[i+2]+dp[i+6]);
        }
        printf("%lld\n", dp[0]);
    }
}

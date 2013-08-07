#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MOD 761238923

int N;
int dp [101][101];

int count(int n, int balls){
    if (n==N)
        if (balls==N)
            return 1;
        else return 0;
    if (dp[n][balls]!=-1)
        return dp[n][balls];
    dp[n][balls] = 0;
    for (int i=balls;i<=n+1;i++)
        dp[n][balls] = ((dp[n][balls]%MOD)+(count(n+1,i)%MOD))%MOD;
    return dp[n][balls];
}

int main(){
    scanf("%d", &N);
    while(N){
        memset(dp, -1, sizeof dp);
        printf("%d\n", count(0,0));
        scanf("%d", &N);
    }
}

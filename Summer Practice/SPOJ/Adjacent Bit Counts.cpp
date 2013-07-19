#include<stdio.h>
#include<string.h>

using namespace std;

long long dp[101][101][2];

int N;

long long maximize(int n, int k, int val){
    if (n==N)
        return k==0?1:0;
    if (dp[n][k][val]!=-1)
        return dp[n][k][val];
    if (k==0){
        if (val)
            return dp[n][k][val] = maximize(n+1,k,0);
        else return dp[n][k][val] = maximize(n+1,k,0) + maximize(n+1,k,1);
    }
    if (val)
        return dp[n][k][val] = maximize(n+1,k,0)+maximize(n+1,k-1,1);
    else return dp[n][k][val] = maximize(n+1,k,0) + maximize(n+1,k,1);
}

int main(){
    int t,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&x,&y,&z);
        N = y;
        memset(dp,-1,sizeof dp);
        printf("%d %lld\n",x,maximize(1,z,0)+maximize(1,z,1));
    }
}

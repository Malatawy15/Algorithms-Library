#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char exp [110];
long long dp[200][200];

long long calc(int i, int j){
    if (i==j)
        return (exp[i]-'0');
    if (j-i==2){
        if (exp[i+1]=='+')
            return (exp[j]-'0') + (exp[i]-'0');
        else return (exp[j]-'0') * (exp[i]-'0');
    }
    if (dp[i][j]!=-1)
        return dp[i][j];
    for (int x = i;x<j;x+=2){
        if (exp[x+1]=='+')
            dp[i][j] = max(dp[i][j],calc(i,x)+calc(x+2,j));
        else dp[i][j] = max(dp[i][j],calc(i,x)*calc(x+2,j));
    }
    return dp[i][j];
}

long long calc_min(int i, int j){
    if (i==j)
        return (exp[i]-'0');
    if (j-i==2){
        if (exp[i+1]=='+')
            return (exp[j]-'0') + (exp[i]-'0');
        else return (exp[j]-'0') * (exp[i]-'0');
    }
    if (dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = 1000000000;
    for (int x = i;x<j;x+=2){
        if (exp[x+1]=='+')
            dp[i][j] = min(dp[i][j],calc_min(i,x)+calc_min(x+2,j));
        else dp[i][j] = min(dp[i][j],calc_min(i,x)*calc_min(x+2,j));
    }
    return dp[i][j];
}

int main(){
    int t, len;
    long long res1, res2;
    scanf("%d", &t);
    while(t--){
        scanf("%s", exp);
        len = strlen(exp);
        memset(dp,-1,sizeof dp);
        res1 = calc(0,len-1);
        memset(dp,-1,sizeof dp);
        res2 = calc_min(0,len-1);
        printf("%lld %lld\n", res1, res2);
    }
}

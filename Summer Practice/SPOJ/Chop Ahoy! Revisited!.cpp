#include<stdio.h>
#include<string.h>

using namespace std;

int N;
char num[30];
int dp[30][300];

int count(int n, int prev){
    if (n>=N)
        return 1;
    if (dp[n][prev]!=-1)
        return dp[n][prev];
    dp[n][prev] = 0;
    int sum = 0;
    for (int i=n;i<N;i++){
        sum+=num[i]-'0';
        if (sum>=prev)
            dp[n][prev] += count(i+1,sum);
    }
    return dp[n][prev];
}

int main(){
    int cs = 0;
    scanf("%s",num);
    while(strcmp(num,"bye")!=0){
        N = strlen(num);
        memset(dp,-1,sizeof dp);
        printf("%d. %d\n",++cs, count(0,0));
        scanf("%s",num);
    }
}

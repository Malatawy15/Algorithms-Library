#include<stdio.h>
#include<string.h>

using namespace std;

int num, k;
int dp[6][100010];
int vals[6];
int main(){
    scanf("%d %d",&num,&k);
    vals[0] = 0;
    for (int i=1;i<=k;i++){
        scanf("%d", &vals[i]);
        vals[i]+=vals[i-1];
    }
    memset(dp,0,sizeof dp);
    for (int i=1;i<=k;i++)
        dp[i][vals[i]] = 1;
    for (int i=1;i<=k;i++)
        for (int j=0;j<=num;j++){
            dp[i][j]|=dp[i-1][j];
            if (j-vals[i]>=0){
                dp[i][j]|=dp[i][j-vals[i]];
                dp[i][j]|=dp[i-1][j-vals[i]];
            }
        }
    if (dp[k][num])
        printf("YES\n");
    else printf("NO\n");
}

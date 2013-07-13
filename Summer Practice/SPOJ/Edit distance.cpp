#include<stdio.h>
#include<string.h>

using namespace std;

int dp[3010][3010];

int main(){
    int t;
    scanf("%d",&t);
    char str1[3001];
    char str2[3001];
    int s1, s2;
    while(t--){
        scanf("%s",str1);
        scanf("%s",str2);
        s1 = strlen(str1);
        s2 = strlen(str2);
        for (int i=0;i<=s1;i++)
            dp[i][0] = i;
        for (int i=0;i<=s2;i++)
            dp[0][i] = i;
        for (int i=1;i<=s1;i++)
            for (int j=1;j<=s2;j++){
                dp[i][j] = dp[i-1][j-1];
                if (str1[i-1]!=str2[j-1])
                    dp[i][j]++;
                if (dp[i][j]>dp[i-1][j]+1)
                    dp[i][j] = dp[i-1][j]+1;
                if (dp[i][j]>dp[i][j-1]+1)
                    dp[i][j] = dp[i][j-1]+1;
            }
        printf("%d\n",dp[s1][s2]);
    }
}

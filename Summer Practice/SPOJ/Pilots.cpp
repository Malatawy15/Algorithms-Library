#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N;
int vals[10010][2];
int dp[10010][2];

int main(){
    scanf("%d", &N);
    dp[0][0] = 0;
    int f = 1, l = 0, tmp;
    for (int i=N;i>=1;i--)
        scanf("%d %d",&vals[i][0], &vals[i][1]);
    for (int i=1;i<N;i++){
        for (int j=0;j<=i;j++)
            dp[j][f] = 1000000000;
        for (int j=1;j<=i/2;j++){
            if (i>2)
                dp[i-j][f] = min(dp[i-j][l]+vals[i][1],dp[i-j-1][l]+vals[i][0]);
            else dp[i-j][f] = dp[i-j][l]+vals[i][1];
            //printf("%d %d %d\n",i,j,dp[i-j][f]);
        }
        dp[i][f] = dp[i-1][l]+vals[i][0];
        //printf("%d %d %d\n",i,i,dp[i][f]);
        tmp = f;
        f = l;
        l = tmp;
    }
    printf("%d\n", dp[N/2][1]+vals[N][1]);
}

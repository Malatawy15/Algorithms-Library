#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int dp[101][101];

int main(){
    memset(dp,0,sizeof dp);
    int N, M, x, y;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        dp[x-1][y-1] = 1;
    }
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++){
            if (i>0)dp[i][j]+=dp[i-1][j];
            if (j>0)dp[i][j]+=dp[i][j-1];
            if (i>0 && j>0)dp[i][j]-=dp[i-1][j-1];
        }
    int maxSum = -100000000, curSum, numSq, curTop;
    for (int i=0;i<N;i++)for (int j=0;j<N;j++)
    for (x = i;x<N;x++) for (y=j;y<N;y++){
        numSq = (x-i+1)*(y-j+1);
        if (numSq==M){
            curSum = dp[x][y];
            if (i>0)curSum-=dp[i-1][y];
            if (j>0)curSum-=dp[x][j-1];
            if (i>0 && j>0)curSum+=dp[i-1][j-1];
            maxSum = max(maxSum, curSum);
        }
    }
    printf("%d\n", M-maxSum);
}

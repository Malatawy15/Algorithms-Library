#include<stdio.h>
#include<string.h>

int S;
long long dp[6][100010];

void precompute(){
    int vals[6];
    vals[1] = 2;
    vals[2] = 3;
    vals[3] = 6;
    vals[4] = 7;
    vals[5] = 8;
    int i,j;
    for (i=1;i<6;i++)
        for (j=0;j<=100000;j++){
            dp[i][j] = 0LL;
            if (j==vals[i])
                dp[i][j]++;
            dp[i][j]+=dp[i-1][j];
            if (j-vals[i]>=0)
                dp[i][j]+=dp[i][j-vals[i]];
        }
}


int main(void){
    int t;
    scanf("%d", &t);
    precompute();
    while(t--){
        scanf("%d", &S);
        if (S==0)
            printf("1\n");
        else printf("%lld\n", dp[5][S]);
    }
    return 0;
}

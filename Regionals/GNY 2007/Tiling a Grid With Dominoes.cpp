#include <stdio.h>
#include <string.h>

using namespace std;

int R, C;

int dp [5][100001];

int count(int l, int w){
    printf("CALL: %d %d\n", l, w);
    if (l<2&&w<2)
        return 0;
    if (l==0||w==0)
        return 0;
    if ((l==2&&w==1)||(w==2&&l==1))
        return 1;
    if (dp[l][w]!=-1)
        return dp[l][w];
    dp[l][w] = 0;
//    if (C%2==0)
    for (int i=1;i<l;i++){
        dp[l][w]+=(count(i,w)*count(l-i,w));
    }
//    else
    for (int i=1;i<w;i++){
        dp[l][w]+=(count(l,i)*count(l,w-i));
    }
    printf("RES: %d %d %d\n",l,w,dp[l][w]);
    return dp[l][w];
}

int main(){
    int t, cn = 1;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);
        scanf("%d", &C);
        printf("%d %d\n", cn++, count(4, C));
    }
}

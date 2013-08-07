#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int W, H, N;
int vals[210][2];
int dp[601][601];

int maximize(int w, int h){
    //printf("CALL: %d %d\n", w, h);
    if (dp[w][h]!=-1)
        return dp[w][h];
    dp[w][h] = 0;
    for (int i=0;i<N;i++)
        if (w>=vals[i][0]&&h>=vals[i][1]){
            //printf("Use: %d %d\n", vals[i][0], vals[i][1]);
            dp[w][h] = max(dp[w][h], vals[i][0]*vals[i][1]+max(maximize(w-vals[i][0], vals[i][1])+maximize(w,h-vals[i][1]),maximize(vals[i][0], h-vals[i][1])+maximize(w-vals[i][0],h)));
        }
    //printf("%d %d %d\n",w,h,dp[w][h]);
    return dp[w][h];
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &W, &H);
        scanf("%d", &N);
        for (int i=0;i<N;i++)
            scanf("%d %d", &vals[i][0], &vals[i][1]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", W*H-maximize(W,H));
    }
}

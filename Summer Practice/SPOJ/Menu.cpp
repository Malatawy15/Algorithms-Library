#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define Pair pair<int, int>

int D, N, B;
int dp[23][52][102][2][3];
int vals [52][2];

Pair maximize(int d, int n, int rem, int sc){
    if (d==D)
        return Pair(0, rem);
    if (dp[d][n][rem][sc][0]!=-1)
        return Pair(dp[d][n][rem][sc][0], dp[d][n][rem][sc][1]);
    dp[d][n][rem][sc][0] = -100000000;
    dp[d][n][rem][sc][1] = 0;
    for (int i=1;i<=N;i++){
        if (vals[i][0]<=rem){
            Pair p;
            if (i==n){
                if (sc==0){
                    p = maximize(d+1, i, rem-vals[i][0],1);
                    p.first+= (vals[i][1]);
                }
                else if (sc==1){
                    p = maximize(d+1, i, rem-vals[i][0],1);
                }
            }
            else {
                p = maximize(d+1, i, rem-vals[i][0],0);
                p.first+= (vals[i][1]<<1);
            }
            if (p.first<0)
            	continue;
            if (p.first>dp[d][n][rem][sc][0]||(p.first==dp[d][n][rem][sc][0]&&p.second>dp[d][n][rem][sc][1])){
                dp[d][n][rem][sc][0] = p.first;
                dp[d][n][rem][sc][1] = p.second;
                dp[d][n][rem][sc][2] = i;
            }
        }
    }
    return Pair(dp[d][n][rem][sc][0],dp[d][n][rem][sc][1]);
}

void roll_back(int d, int n, int rem, int sc){
    if (d==D)
        return;
    printf("%d ", dp[d][n][rem][sc][2]);
    int gt = dp[d][n][rem][sc][2];
    if (gt==n){
        if (sc==0){
            roll_back(d+1, gt, rem-vals[gt][0],1);
        }
        else if (sc==1){
            roll_back(d+1, gt, rem-vals[gt][0],1);
        }
    }
    else roll_back(d+1, gt, rem-vals[gt][0], 0);
}

int main(){
    scanf("%d %d %d", &D, &N, &B);
    while(!(!D&&!N&&!B)){
        for (int i=1;i<=N;i++){
            scanf("%d %d", &vals[i][0], &vals[i][1]);
        }
        memset(dp,-1,sizeof dp);
        Pair p = maximize(0,0,B,1);
        if (p.first<=0){
            printf("0.0\n\n");
        }
        else {
            printf("%.1lf\n", p.first/2.0);
            roll_back(0,0,B,1);
            printf("\n");
        }
        scanf("%d %d %d", &D, &N, &B);
    }
}

//days start at 0
//meals start at 1

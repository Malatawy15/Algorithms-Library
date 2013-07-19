#include<stdio.h>
#include<string.h>

using namespace std;

int dx[]={-2,2,1,1,-1,-1};
int dy[]={0,0,-1,1,-1,1};

int dp[100][100][20];

int count(int x, int y, int rem){
    if (rem==0)
        return x==50&&y==50?1:0;
    if (dp[x][y][rem]!=-1)
        return dp[x][y][rem];
    dp[x][y][rem] = 0;
    for (int i=0;i<6;i++){
        dp[x][y][rem]+=count(x+dx[i],y+dy[i],rem-1);
    }
    return dp[x][y][rem];
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        printf("%d\n", count(50,50,n));
    }
}

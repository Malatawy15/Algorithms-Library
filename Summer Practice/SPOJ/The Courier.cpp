#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define INF 1000000000

int N, M, D, Z, O;
int adj[101][101];
int dp [101][5000];
int orders [13][2];
int pows[] = {0,1,3,7,15,31,63,127,255,511,1023,2047,4095};

int minimize(int n, int bitmask){
    if (bitmask==pows[O])
        return adj[n][D];
    if (dp[n][bitmask]!=-1)
        return dp[n][bitmask];
    dp[n][bitmask] = INF;
    for (int i=0;i<O;i++){
        if (!(bitmask&(1<<i))){
            dp[n][bitmask] = min(dp[n][bitmask], adj[n][orders[i][0]]+adj[orders[i][0]][orders[i][1]]+minimize(orders[i][1], bitmask|(1<<i)));
        }
    }
    return dp[n][bitmask];
}

int main(){
    int t,x,y,z;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &N, &M, &D);
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if (i!=j)
                    adj[i][j] = INF;
                else adj[i][j] = 0;
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &x, &y, &z);
            adj[x][y] = min(adj[x][y], z);
            adj[y][x] = min(adj[y][x], z);
        }
        scanf("%d", &Z);
        O = 0;
        for (int i=0;i<Z;i++){
            scanf("%d %d %d", &orders[O][0], &orders[O][1], &x);
            for (int i=O+1;i<O+x;i++){
                orders[i][0] = orders[O][0];
                orders[i][1] = orders[O][1];
            }

            O+=x;
        }
        for (int k=1;k<=N;k++)
            for (int i=1;i<=N;i++)
                for (int j=1;j<=N;j++)
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
        memset(dp,-1,sizeof dp);
        printf("%d\n", minimize(D, 0));
    }
}

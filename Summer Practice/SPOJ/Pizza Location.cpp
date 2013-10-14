#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <math.h>

using namespace std;

int N, K, M, R;

int dp[21][1048577];
int vis[21][1048577];
bitset<100> can[20];
int vals[100];
int pos[20][2];

int maximize(int n, int k, int bitmask){
    if (k<0)
        return -10000;
    if (N-n<k)
    	return -10000;
    if (vis[n][bitmask])
        return dp[n][bitmask];
    vis[n][bitmask] = 1;
    if (n==N){
        int sum = 0;
        bitset<100> bs;
        for (int i=0;i<N;i++)
        	if (bitmask&(1<<i))
        		bs|=can[i];
        for (int i=0;i<M;i++){
        	if (bs[i])
        		sum+=vals[i];
        }
        return dp[n][bitmask] = sum;
    }
    return dp[n][bitmask] = max(maximize(n+1,k,bitmask), maximize(n+1, k-1, bitmask|(1<<n)));
}

int main(){
    int x,y,z;
    scanf("%d %d", &K, &R);
    R*=R;
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    scanf("%d", &M);
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &vals[i]);
        for (int j=0;j<N;j++){
            if ((x-pos[j][0])*(x-pos[j][0])+(y-pos[j][1])*(y-pos[j][1])<=R)
                can[j][i] = 1;
            else can[j][i] = 0;
        }
    }
    printf("%d\n", maximize(0,K,0));
}

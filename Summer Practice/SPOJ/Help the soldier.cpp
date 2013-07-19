#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Eq pair<int, int>
#define cost first
#define quality second
#define INF 1000000000

vector<Eq> arr[7];
int dp[7][1005];

int maximize(int n, int rem){
    //printf("%d %d\n", n, rem);
    if (n==7)
        return INF;
    if (dp[n][rem]!=-1) return dp[n][rem];
    dp[n][rem] = 0;
    for (int i=0;i<arr[n].size();i++)
        if (arr[n][i].cost<=rem)
            dp[n][rem] = max(dp[n][rem], min(arr[n][i].quality, maximize(n+1, rem-arr[n][i].cost)));
    return dp[n][rem];
}

int main(){
    int N, T, x, y, z;
    scanf("%d %d", &N, &T);
    for (int i=0;i<N;i++){
        scanf("%d %d %d", &x, &y, &z);
        arr[x].push_back(Eq(y,z));
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", maximize(1,T));
}

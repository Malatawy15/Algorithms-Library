#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

int F, V;
int dp[103][103];
int cm[103][103];
int vis[103][103];
int vals[103][103];
/*
int maximize(int f, int v){
    if (f==F)
        return 0;
    if (F-f>V-v)
        return -1000000000;
    if (vis[f][v]) return dp[f][v];
    vis[f][v] = 1;
    dp[f][v] = -1000000000;
    for (int i=v+1;i<V;i++)

}
*/

int main(){
    scanf("%d %d", &F, &V);
    for (int i=1;i<=F;i++)
        for (int j=1;j<=V;j++)
            scanf("%d", &vals[i][j]);
    for (int i=0;i<=V;i++) dp[0][i] = 0;
    for (int i=1;i<=F;i++) dp[i][0] = -1000000000;

    for (int i=1;i<=F;i++)
        for (int j=1;j<=V;j++){
            dp[i][j] = -1000000000;
            for (int k=0;k<j;k++)
                if (dp[i-1][k]>dp[i][j]){
                    cm[i][j] = k;
                    dp[i][j] = dp[i-1][k];
                }
            dp[i][j] += vals[i][j];
        }
    vector<int> v;
    int maxV = -1000000000, maxI;
    for (int i=0;i<=V;i++)
        if (dp[F][i]>maxV){
            maxV = dp[F][i];
            maxI = i;
        }
    v.push_back(maxI);
    for (int i=F;i>1;i--){
        int x = cm[i][v[F-i]];
        v.push_back(x);
    }
    printf("%d\n", maxV);
    printf("%d",v[F-1]);
    for (int i=1;i<v.size();i++) printf(" %d",v[F-1-i]);
    printf("\n");
}

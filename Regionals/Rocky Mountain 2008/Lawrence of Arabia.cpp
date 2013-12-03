#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int dp[1001][1001][2][2];
int pre [1001][1001];
int vals[1001];


pair<int, int> minimize(int n, int m, int s){
    if (m==0)
        return make_pair(pre[n][N-1],-1);
    if (n==N-1)
        return make_pair(0,n);
    if (dp[n][m][s][0]!=-1)
        return make_pair(dp[n][m][s][0],dp[n][m][s][1]);
    pair<int, int> p1 = minimize(n+1,m-1,1);
    pair<int, int> p2 = minimize(n+1,m,0);
    pair<int, int> ret;
    //if (p1.first>p2.first+pre[n][p2.second])
      //  p1 = p2;
    if (s){
        if (p1.second==-1){
            ret = p1;
        }
        else{
            ret = make_pair(p1.first+pre[n][p1.second],-1);
        }
        dp[n][m][s][0] = ret.first;
        dp[n][m][s][1] = ret.second;
        //printf("STEP: %d %d %d: %d %d\n",n,m,s,dp[n][m][s][0],dp[n][m][s][1]);
        return ret;
    }
    else{
        dp[n][m][s][0] = p1.first;
        dp[n][m][s][1] = p1.second;
        //printf("STEP: %d %d %d: %d %d\n",n,m,s,dp[n][m][s][0],dp[n][m][s][1]);
        return p1;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    while(!(!N&&!M)){
        for (int i=0;i<N;i++)
            scanf("%d", &vals[i]);

        pre[N-1][N-1] = 0;
        for (int i=N-2;i>=0;i--)
            for (int j=i;j<N;j++)
                if (i==j)
                    pre[i][j] = 0;
                else pre[i][j] = vals[i]*vals[j]+pre[i][j-1]+pre[i+1][j]-pre[i+1][j-1];
        //printf("CALL DP\n");
        memset(dp, -1, sizeof dp);
        printf("%d\n", minimize(0, M, 1).first);
        scanf("%d %d", &N, &M);
    }
}

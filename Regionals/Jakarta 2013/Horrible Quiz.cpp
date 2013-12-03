#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

long long dp[1300][1300];
vector<int> cor, wor;

int main(){
    int t;
    scanf("%d", &t);
    int N, M, cn = 1;
    int d;
    while(t--){
        memset(dp,0,sizeof dp);
        cor.clear();
        wor.clear();
        scanf("%d %d", &N, &M);
        dp[0][0] = 15000LL;
        wor.push_back(0);
        cor.push_back(0);
        for (int i=0;i<N;i++){
            scanf("%d", &d);
            cor.push_back(d);
        }
        for (int i=0;i<N;i++){
            scanf("%d", &d);
            wor.push_back(d);
        }
        for (int i=1;i<=N;i++)
        for (int j=0;j<=M&&j<=i;j++){
            if (j==0){
                dp[i][j] = (dp[i-1][j])*(cor[i]+(100-cor[i]-wor[i]))-(dp[i-1][j])*(wor[i]);
            }
            else if (j==i){
                dp[i][j] = (dp[i-1][j-1])*(cor[i])-(dp[i-1][j-1])*(wor[i]+(100-cor[i]-wor[i]));
            }
            else {
                long long cr = 0LL, wr=0LL;
                cr = (dp[i-1][j])*(cor[i]+(100-cor[i]-wor[i]))-(dp[i-1][j])*(wor[i]);
                wr = (dp[i-1][j-1])*(cor[i])-(dp[i-1][j-1])*(wor[i]+(100-cor[i]-wor[i]));
                dp[i][j] = min(cr,wr);
            }
        }

        long long mini = 1000000000000000LL, fac = 0LL;
        for (int i=0;i<=M;i++){
            if (dp[N][i]<mini){
                fac = i;
                mini = dp[N][i];
            }
        }
        printf("Case #%d: %.3lf %d\n", cn++, mini*1.0/pow(100.0,M+fac+1),fac);
    }
}

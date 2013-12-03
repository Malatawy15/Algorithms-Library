#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

double dp[1301][1301];

int main(){
    int t;
    scanf("%d", &t);
    int N, M, cn = 1;
    double d;
    vector<double> cor, wor;
    while(t--){
        cor.clear();
        wor.clear();
        scanf("%d %d", &N, &M);
        dp[0][0] = 15000.0;
        wor.push_back(0);
        cor.push_back(0);
        for (int i=0;i<N;i++){
            scanf("%lf", &d);
            cor.push_back(d);
        }
        for (int i=0;i<N;i++){
            scanf("%lf", &d);
            wor.push_back(d);
        }
        for (int i=1;i<=N;i++)
        for (int j=0;j<=M&&j<=i;j++){
            if (j==0){
                dp[i][j] = ((dp[i-1][j])*(cor[i]+(100-cor[i]-wor[i]))-(dp[i-1][j])*(wor[i]))/100.0+(1e-9);
            }
            else if (j==i){
                dp[i][j] = ((dp[i-1][j-1])*(cor[i])-(dp[i-1][j-1])*(wor[i]+(100-cor[i]-wor[i])))/100.0+(1e-9);
            }
            else {
                double cr, wr;
                cr = ((dp[i-1][j])*(cor[i]+(100-cor[i]-wor[i]))-(dp[i-1][j])*(wor[i]))/100.0;
                wr = ((dp[i-1][j-1])*(cor[i])-(dp[i-1][j-1])*(wor[i]+(100-cor[i]-wor[i])))/100.0;
                dp[i][j] = min(cr,wr)+(1e-9);
            }
        }
        double mini = 100000000000000.0;
        for (int i=0;i<=M;i++)
            mini = min(mini, dp[N][i]);
        printf("Case #%d: %.3lf\n", cn++, mini+(1e-9));
    }
}

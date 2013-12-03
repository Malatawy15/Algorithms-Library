#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N;
double B;
int vals[101];
double dp[102][102];
double dis[10001];

double maximize(int n, int l){
    if (n==N)
    	return dis[vals[N]-vals[l]];
    if (dp[n][l]>-1)
        return dp[n][l];
    return dp[n][l] = min(maximize(n+1,l), dis[vals[n]-vals[l]]+B+maximize(n+1,n));
}

int main(){
    int r;
    double v,e,f;
    scanf("%d", &N);
    while(N){
        for (int i=0;i<=N;i++)
            for (int j=0;j<=N;j++)
                dp[i][j] = -2;
        vals[0] = 0;
        for (int i=1;i<=N;i++)
            scanf("%d", &vals[i]);
        scanf("%lf", &B);
        scanf("%d %lf %lf %lf",&r,&v,&e,&f);
        dis[0] = 0.0;
        for (int i=1;i<=vals[N];i++){
            dis[i] = dis[i-1];
            if ((i-1)<r){
                dis[i] += (1.0/(v-f*(r-(i-1))));
            }
            else dis[i] += (1.0/(v-e*((i-1)-r)));
        }
        printf("%.4lf\n", maximize(0,0));
        scanf("%d", &N);
    }
}

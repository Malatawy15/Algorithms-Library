#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Dis pair<int, int>

int N, cc;
vector<Dis> graph[20];
int vals[20][2];
double discounts[20];
double dp[17][33000][2];
int vis[17][33000][2];

pair<double, double> minimize(int n, int bitmask){
    //printf("Call: %d %d\n",n,bitmask);
    if (n==N)
        return make_pair(0,0);
    if (vis[n][bitmask][0]==cc)
        return make_pair(dp[n][bitmask][0]+vals[n][0]*discounts[n], dp[n][bitmask][1]+vals[n][1]);
    vis[n][bitmask][0] = cc;
    int nbit = bitmask|(1<<n);
    for (int i=0;i<graph[n].size();i++)
        discounts[graph[n][i].first]*=(1.0-graph[n][i].second/100.0);
    double res = vals[n][0]*discounts[n]/(1.0*vals[n][1]);
    double rp = 0, ra = 0;
    pair<double, double> pret;
    for (int i=0;i<graph[n].size();i++){
         if (!(nbit&(1<<graph[n][i].first))){
             pret = minimize(graph[n][i].first, nbit);
             if ((pret.first+vals[n][0]*discounts[n])/(pret.second+1.0*vals[n][1])<res){
                 res = (pret.first+vals[n][0]*discounts[n])/(pret.second+1.0*vals[n][1]);
                 rp = (pret.first);
                 ra = (pret.second);
             }
         }
    }
    for (int i=0;i<graph[n].size();i++)
        discounts[graph[n][i].first]/=(1.0-graph[n][i].second/100.0);
    dp[n][bitmask][0] = rp;
    dp[n][bitmask][1] = ra;
    return make_pair((rp+vals[n][0]*discounts[n]), ra+1.0*vals[n][1]);
}

int main(){
    int x,y,z;
    cc = 0;
    scanf("%d",&N);
    while(N){
        cc++;
        for (int i=0;i<N;i++){
            scanf("%d %d %d", &vals[i][0], &vals[i][1], &z);
            for (int j=0;j<z;j++){
                scanf("%d %d",&x,&y);
                graph[i].push_back(make_pair(x,y));
            }
        }
        double res = 1000000000;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++)
                discounts[j] = 1.0;
            pair<double, double> ret = minimize(i,0);
            if (ret.first/ret.second<res)
                res = ret.first/ret.second;
        }
        for (int i=0;i<N;i++)
            graph[i].clear();
        printf("%lf\n", res);
        scanf("%d",&N);
    }
}

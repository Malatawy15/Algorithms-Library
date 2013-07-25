#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
#define INF 1000000000
#define Pizza pair<double, int>
#define Disc pair<int, double>


int N, allVis;
double dp[16][33000][2];
vector<Disc> discounts[16];
int areas[16];
int prices[16];
double dis[16];

Pizza minimize(int n, int bitmask){
    if (dp[n][bitmask][0]!=-1)
        return Pizza(dp[n][bitmask][0]+prices[n]*dis[n], dp[n][bitmask][1]+areas[n]);
    printf("%d %d %lf\n", n, bitmask, dis[n]);
    dp[n][bitmask][0] = INF;
    dp[n][bitmask][1] = INF;
    double mini = INF;
    Pizza ret, minz;
    int nbit = bitmask|(1<<n);
    for (int i=0;i<discounts[n].size();i++){
        //printf("HERE %d %lf %lf\n",discounts[n][i].first, discounts[n][i].second,dis[discounts[n][i].first]);
        dis[discounts[n][i].first]*=(discounts[n][i].second);
    }
    for (int i=0;i<discounts[n].size();i++){
        if (!(nbit&(1<<discounts[n][i].first))){
            ret = minimize(discounts[n][i].first, nbit);
            if (ret.first/ret.second<mini){
                mini = ret.first/ret.second;
                minz = ret;
            }
        }
    }
    for (int i=0;i<discounts[n].size();i++)
        dis[discounts[n][i].first]/=(discounts[n][i].second);
    if (mini == INF){
        dp[n][bitmask][0] = 0;
        dp[n][bitmask][1] = 0;
        return Pizza(prices[n]*dis[n], areas[n]);
    }
    else{
        dp[n][bitmask][0]=minz.first;
        dp[n][bitmask][1]=minz.second*1.0;
        if ((dp[n][bitmask][0]+prices[n]*dis[n])/(dp[n][bitmask][1]+areas[n])<prices[n]*dis[n]/areas[n]){
            printf("Choose %d %d %lf 1\n",n,bitmask,(dp[n][bitmask][0]+prices[n]*dis[n])/(dp[n][bitmask][1]+areas[n]));
            return Pizza(minz.first+prices[n]*dis[n], minz.second+areas[n]);
        }
        else {
            printf("Choose %d %d %lf 2\n",n,bitmask,prices[n]*dis[n]/areas[n]);
            return Pizza(prices[n]*dis[n], areas[n]);
        }
    }
}
/*
double minimize(int n, int bitmask){
    //printf("%d %d %d %d %lf\n",n,dis,bitmask,allVis,dp[n][dis][bitmask]);
    double pc = prices[n]*dis[n];
    pc/=100.0;
    double pa=pc/areas[n];
    if (dp[n][bitmask][0]!=-1)
        if (dp[n][bitmask][1]==INF)
            return pa;
        else return min(pa, (pa+dp[n][bitmask][1])/2.0);
    int nbit = bitmask|(1<<n);
    dp[n][bitmask][0] = pa;
    dp[n][bitmask][1] = INF;
    for (int i=0;i<N;i++)
        dis[i]*=(1-discounts[n][i]);
    for (int i=0;i<N;i++)
        if (!(nbit&(1<<i))&&discounts[n][i]!=0){
            double ret = minimize(i, nbit);
            if (ret<dp[n][bitmask][1])
                dp[n][bitmask][1] = ret;
            dp[n][bitmask][0] = min(dp[n][bitmask][0], (pa+ret)/2.0);
        }
    for (int i=0;i<N;i++)
        dis[i]/=(1-discounts[n][i]);
    return dp[n][bitmask][0]/dp[n][bitmask][1];
}
*/
int main(){
    int x,y,z;
    scanf("%d", &N);
    memset(dis, 0, sizeof dis);
    while(N){
        for (int i=0;i<16;i++)
            for (int j=0;j<33000;j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        for (int i=0;i<N;i++){
            scanf("%d %d %d", &prices[i],&areas[i],&z);
            for (int j=0;j<z;j++){
                scanf("%d %d", &x,&y);
                discounts[i].push_back(Disc(x-1, 1-y/100.0));
            }
        }
        double mini = INF;
        for (int i=0;i<N;i++){
            for (int i=0;i<N+5;i++)
                dis[i] = 1.0;
            Pizza p = minimize(i,0);
            mini = min(mini, p.first*1.0/p.second);
        }
        printf("%lf\n", mini);
        for (int i=0;i<N;i++)
            discounts[i].clear();
        scanf("%d", &N);
    }
}

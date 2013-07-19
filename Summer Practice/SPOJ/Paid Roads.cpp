#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Road pair<int, pair<int, int> >
#define des first
#define itr second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))
#define INF 100000000
int dp[11][2000];
int vis[11][2000];

vector<Road> direct[11];
vector<Road> indirect[11];
int N, M;

int minimize(int n, int bitmask){
    //printf("%d %d\n", n, bitmask);
    if (n==N-1)
        return 0;
    if (vis[n][bitmask])
        return dp[n][bitmask];
    vis[n][bitmask] = 1;
    int nbit = bitmask|(1<<n);
    dp[n][bitmask] = INF;
    for (int i=0;i<direct[n].size();i++)
        dp[n][bitmask] = min(dp[n][bitmask],direct[n][i].cost+minimize(direct[n][i].des, nbit));
    for (int i=0;i<indirect[n].size();i++){
        Road r1 = indirect[n][i];
        if (bitmask&(1<<r1.itr))
            dp[n][bitmask] = min(dp[n][bitmask],r1.cost+minimize(r1.des, nbit));
    }
    return dp[n][bitmask];
}

int main(){
    int a,b,c,d,e;
    scanf("%d %d", &N, &M);
    while(M--){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        a--;b--;c--;
        direct[a].push_back(mp(b,-1,e));
        indirect[a].push_back(mp(b,c,d));
    }
    memset(vis,0,sizeof vis);
    int ret = minimize(0,0);
    if (ret==INF)
        printf("impossible");
    else printf("%d", ret);
}

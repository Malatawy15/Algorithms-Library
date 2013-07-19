#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Node pair<int, int>
#define INF 1000000000

double dp [33][300];
int tickets[8];
vector<Node> graph[33];

int n,m,p,a,b;

double minimize(int ind, int bitmask){
    if (ind==b)
        return 0;
    if (dp[ind][bitmask]!=-1) return dp[ind][bitmask];
    dp[ind][bitmask] = INF;
    for (int i=0;i<graph[ind].size();i++){
        for (int j=0;j<n;j++)
            if (!(bitmask&(1<<j)))
                dp[ind][bitmask] = min(dp[ind][bitmask], (graph[ind][i].second*1.0/tickets[j])+minimize(graph[ind][i].first, bitmask|(1<<j)));
    }
    return dp[ind][bitmask];
}

int main(){
    int x,y,z,flag = 1;
    scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    while(!(!n&&!m&&!p&&!a&&!b)){
        for (int i=0;i<n;i++)
            scanf("%d", &tickets[i]);
	    if (flag)
            flag = 0;
	    else
        for (int i=0;i<=m;i++)
            graph[i].clear();
        for (int i=0;i<p;i++){
            scanf("%d %d %d", &x, &y, &z);
            graph[x].push_back(Node(y,z));
            graph[y].push_back(Node(x,z));
        }
        for (int i=0;i<m+2;i++)
            for (int j=0;j<257;j++)
                dp[i][j] = -1;
        double ret = minimize(a,0);
        if (ret==INF)
            printf("Impossible\n");
        else printf("%lf\n", ret);
        scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    }
}

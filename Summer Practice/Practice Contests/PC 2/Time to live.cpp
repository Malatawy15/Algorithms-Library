#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

vector<int> graph[100010];
int vis[100010];

int maxi, maxN, ttl;
vector<int> vec;

void dfs1(int node, int step){
    if (vis[node])
        return;
    vis[node] = 1;
    if (step>maxi){
        maxi = step;
        maxN = node;
    }
    for (int i=0;i<graph[node].size();i++)
        dfs1(graph[node][i],step+1);
}

void dfs2(int node, int step){
    if (vis[node])
        return;
    vis[node] = 1;
    vec.push_back(node);
    if (step>maxi){
        maxi = step;
        maxN = vec[step>>1];
        ttl = (step>>1)+(step%2);
    }
    for (int i=0;i<graph[node].size();i++)
        dfs2(graph[node][i],step+1);
    vec.pop_back();
}

int main(){
    int t,x,y,N;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for (int i=1;i<N;i++){
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        maxi = -1;
        memset(vis,0,sizeof vis);
        dfs1(0,0);
        maxi = -1;
        memset(vis,0,sizeof vis);
        vec.clear();
        dfs2(maxN,0);
        printf("%d\n",ttl);
        for (int i=0;i<=N;i++)
            graph[i].clear();
    }
}

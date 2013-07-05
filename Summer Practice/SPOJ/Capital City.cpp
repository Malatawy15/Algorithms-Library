#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[100010];
vector<int> GR[100010];
vector<int> nodes;

int vis[100010];

int lastN;

void dfs1(int node){
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i=0;i<GR[node].size();i++)
        dfs1(GR[node][i]);
    lastN = node;
}

void dfs2(int node){
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i=0;i<G[node].size();i++)
        dfs2(G[node][i]);
    nodes.push_back(node);
}

int main(){
    int N, M, x, y;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        GR[y].push_back(x);
    }
    memset(vis,0,sizeof vis);
    for (int i=0;i<N;i++)
        if (!vis[i])
            dfs1(i);
    memset(vis,0,sizeof vis);
    dfs2(lastN);
    sort(nodes.begin(),nodes.end());
    printf("%d\n",nodes.size());
    for (int i=0;i<nodes.size()-1;i++)
        printf("%d ",nodes[i]);
    printf("%d\n",nodes[nodes.size()-1]);
}

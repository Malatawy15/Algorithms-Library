#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

const int MAX = 111060;

int H, P, S;
vector<int> graph[MAX], graphT[MAX];
int vis[MAX];
int sizes[MAX], comps[MAX];
vector<int> sol;

void dfs1(int node){
    vis[node] = 1;
    for (int i=0;i<graph[node].size();i++){
        if (!vis[graph[node][i]])
            dfs1(graph[node][i]);
    }
    sol.push_back(node);
}

void dfs2(int node, int scc){
    vis[node] = 0;
    sizes[scc]++;
    comps[node] = scc;
    for (int i=0;i<graphT[node].size();i++)
        if (vis[graphT[node][i]])
            dfs2(graphT[node][i], scc);
}

int main(){
    int t,u,v;
    scanf("%d", &t);
    while(t--){
        sol.clear();
        for (int i=0;i<MAX;i++){
            graph[i].clear();
            graphT[i].clear();
            vis[i] = 0;
            sizes[i] = 0;
            comps[i] = 0;
        }
        scanf("%d %d %d",&H,&P,&S);
        for (int i=0;i<S;i++){
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graphT[v].push_back(u);
        }
        for (int i=1;i<=H;i++)
            if (!vis[i])
                dfs1(i);
        int com = 0;
        for (int j=sol.size()-1;j>=0;j--)
            if(vis[sol[j]])
                dfs2(sol[j],com++);
        for (int i=1;i<=H;i++)
            sizes[comps[i]]--;
        int maxi = -1, maxI = -1;
        for (int i=1;i<=H;i++)
        if (sizes[comps[i]]>maxi){
            maxi = sizes[comps[i]];
            maxI = i;
        }
        printf("%d %d\n",maxI, maxi);
    }
    return 0;
}

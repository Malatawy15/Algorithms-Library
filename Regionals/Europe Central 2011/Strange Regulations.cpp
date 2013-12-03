#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int N, M, C, T;
//int cables[8001][8001];
vector<int> graph[101][8001];
int vis[8001];
map<pair<int, int>, int> mp;
map<pair<int, int>, int>::iterator it;

int dfs(int node, int K, int par){
    if (vis[node])
        return 0;
    vis[node] = 1;
    for (int i=0;i<graph[K][node].size();i++){
    	if (graph[K][node][i]!=par)
        	if (!dfs(graph[K][node][i], K, node))
            	return 0;
    }
    return 1;
}

int main(){
    int x,y,z;
    scanf("%d %d %d %d",&N,&M,&C,&T);
    while(!(!N&&!M&&!C&&!T)){
        mp.clear();
        for (int i=0;i<=C;i++)
            for (int j=0;j<=N;j++)
                graph[i][j].clear();
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &x, &y, &z);
            //mp[make_pair(min(x,y), max(x,y))] = z;
            mp.insert(make_pair(make_pair(min(x,y), max(x,y)),z));
            graph[z][y].push_back(x);
            graph[z][x].push_back(y);
        }
        for (int i=0;i<T;i++){
            scanf("%d %d %d", &x,&y,&z);
            it = mp.find(make_pair(min(x,y), max(x,y)));
            if (it==mp.end()){
                printf("No such cable.\n");continue;
            }
            //printf("OWNER: %d\n", it->second);
            if (it->second==z){
                printf("Already owned.\n");continue;
            }
            if (graph[z][x].size()>=2||graph[z][y].size()>=2){
                printf("Forbidden: monopoly.\n");continue;
            }
            memset(vis,0,sizeof vis);
            int oo = it->second;
            graph[z][x].push_back(y);
            graph[z][y].push_back(x);
            if (!dfs(x,z,-1)){
                graph[z][x].pop_back();
                graph[z][y].pop_back();
                printf("Forbidden: redundant.\n");continue;
            }
            remove(graph[oo][x].begin(),graph[oo][x].end(),y);
            remove(graph[oo][y].begin(),graph[oo][y].end(),x);
            mp[make_pair(min(x,y), max(x,y))] = z;
            printf("Sold.\n");
        }
        scanf("%d %d %d %d",&N,&M,&C,&T);
    }
}

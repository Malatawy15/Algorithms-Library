#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Road pair<int, pair<int, int> >
#define mp(a,b,c) make_pair(a, make_pair(b,c))

vector<int> graph[510];
int vis[510];

int N,M;

int dfs(int node){
    if (vis[node])
        return 0;
    vis[node] = 1;
    int count = 1;
    for (int i=0;i<graph[node].size();i++)
        count+=dfs(graph[node][i]);
    return count;
}

int main(){
    scanf("%d %d", &N, &M);
    int x,y,z;
    while(!(N==0&&M==0)){
        vector<Road> v;
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &x, &y, &z);
            v.push_back(mp(z,x,y));
        }
        sort(v.begin(),v.end());
        int maxE = v[M-1].first,ind = M-1;
        while(ind>=0&&v[ind].first==maxE){
            graph[v[ind].second.first].push_back(v[ind].second.second);
            graph[v[ind].second.second].push_back(v[ind].second.first);
            ind--;
        }
        memset(vis, 0 ,sizeof vis);
        maxE = -1;
        for (int i=1;i<=N;i++){
            if (!vis[i]){
                ind = dfs(i);
                maxE = max(maxE,ind);
            }
        }

        printf("%d\n", maxE);
        for (int i=0;i<=N;i++)
            graph[i].clear();
        scanf("%d %d", &N, &M);

    }
}

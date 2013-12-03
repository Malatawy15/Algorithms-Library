#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define Street pair<double, int>
#define cost first
#define id second

int N, M;
int vis[101];
vector<Street> graph[101];

double dij(){
    priority_queue<Street> pq;
    memset(vis, 0, sizeof vis);
    pq.push(Street(1,1));
    while(!pq.empty()){
        Street s = pq.top();
        pq.pop();
        if (s.id==N)
            return s.cost;
        if (vis[s.id])
            continue;
        vis[s.id] = 1;
        for (int i=0;i<graph[s.id].size();i++)
            if (!vis[graph[s.id][i].id])
                pq.push(Street(graph[s.id][i].cost*s.cost,graph[s.id][i].id));
    }
    return 0;
}

int main(){
    int x,y,z;
    scanf("%d", &N);
    while(N){
        scanf("%d", &M);
        for (int i=0;i<=N;i++)
            graph[i].clear();
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &x,&y,&z);
            graph[x].push_back(Street(z/100.0,y));
            graph[y].push_back(Street(z/100.0,x));
        }
        printf("%.6lf percent\n", dij()*100);
        scanf("%d", &N);
    }
}

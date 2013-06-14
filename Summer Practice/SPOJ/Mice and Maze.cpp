#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

#define Path pair<int, int>
#define id second
#define cost first

int N, E, T, M;
vector<Path> graph [110];
int vis[110];

int dijkstra(){
    memset(vis, 0, sizeof vis);
    priority_queue<Path, vector<Path>, greater<Path> > pq;
    pq.push(Path(0,E));
    int sum = 0;
    while(!pq.empty()){
        Path p = pq.top();
        pq.pop();
        if (vis[p.id])
            continue;
        if (p.cost>T)
            return sum;
        sum++;
        vis[p.id] = 1;
        for (int i =0;i<graph[p.id].size();i++){
            if (!vis[graph[p.id][i].id]){
                pq.push(Path(graph[p.id][i].cost+p.cost, graph[p.id][i].id));
            }
        }
    }
    return sum;
}


int main(){
    int x, y, z;
    scanf("%d%d%d%d", &N, &E, &T, &M);
    E--;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &z);
        graph[y-1].push_back(Path(z, x-1));
    }
    printf("%d\n", dijkstra());
}

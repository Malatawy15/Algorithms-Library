#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Road pair<int, int>
#define cost first
#define id second

int N, M, A, B, K, G;
vector<Road> graph[1010];

int vis[1010];
int blocked[1001][1001][4];

int wait_time(int ct, int s, int d){
    if (d<s){
        int tmp = s;
        s = d;
        d = tmp;
    }
    //printf("%d %d %d %d %d\n",blocked[s][d][0],blocked[s][d][1],ct,s,d);
    if (ct>=blocked[s][d][0]&&ct<=blocked[s][d][1]){
        //printf("%d %d %d\n",blocked[s][d][0],blocked[s][d][1],ct);
        return blocked[s][d][1]-ct+1;
    }
    else if (ct>=blocked[s][d][2]&&ct<=blocked[s][d][3]){
        //printf("%d %d %d\n",blocked[s][d][2],blocked[s][d][3],ct);
        return blocked[s][d][3]-ct+1;
    }
    else return 0;
}

int dijkstra(int s, int d){
    memset(vis, 0, sizeof vis);
    priority_queue<Road, vector<Road>, greater<Road> > pq;
    pq.push(Road(K,s));
    while(!pq.empty()){
        Road r = pq.top();
        pq.pop();
        if (r.id==d)
            return r.cost;
        if (vis[r.id])
            continue;
        //printf("Node: %d %d\n", r.id, r.cost);
        vis[r.id] = 1;
        for (int i=0;i<graph[r.id].size();i++){
            Road r1 = graph[r.id][i];
            pq.push(Road(r.cost+wait_time(r.cost,r.id,r1.id)+r1.cost,r1.id));
        }
    }
    return -1;
}

int main(){
    int x,y,z;
    memset(blocked, -1, sizeof blocked);
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &A, &B, &K, &G);
    vector<int> path;
    for (int i=0;i<G;i++){
        scanf("%d",&x);
        path.push_back(x);
    }
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &z);
        graph[x].push_back(Road(z,y));
        graph[y].push_back(Road(z,x));
    }
    int ct = 0;
    for (int i=0;i<G-1;i++){
        x = path[i];
        y = path[i+1];
        if (y<x){
            int tmp = x;
            x = y;
            y = tmp;
        }
        for (int i=0;i<graph[x].size();i++){
            Road r = graph[x][i];
            if (r.id==y){
                if (blocked[x][y][0]==-1){
                    blocked[x][y][0] = ct;
                    blocked[x][y][1] = ct+r.cost-1;
                }
                else{
                    blocked[x][y][2] = ct;
                    blocked[x][y][3] = ct+r.cost-1;
                }
                ct += r.cost;
                break;
            }
        }
    }
    printf("%d\n",dijkstra(A,B)-K);
}

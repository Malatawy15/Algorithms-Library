#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define Floor pair<int, int>
#define cost first
#define id second

vector<Floor> graph[1010];
int vis[1010];
int N,M;

int wait_time(int from, int to, int ct){
    int dis = abs(from-to)*10, rem;
    if (from<to){
        rem = ct%dis;
        return (dis-rem)%dis;
    }
    else{
        return ct%dis;
    }
}

int dijkstra(){
    priority_queue<Floor, vector<Floor>, greater<Floor> > pq;
    memset(vis, 0, sizeof vis);
    pq.push(Floor(0,1));
    while(!pq.empty()){
        Floor f = pq.top();
        pq.pop();
        if (f.id==N)
            return f.cost;
        if (vis[f.id])
            continue;
        vis[f.id] = 1;
        for (int i=0;i<graph[f.id].size();i++){
            Floor f1 = graph[f.id][i];
            //printf("%d %d %d\n",f.cost,wait_time(f.id,f1.id,f.cost),f1.cost);
            pq.push(Floor(f.cost+wait_time(f.id,f1.id,f.cost)+f1.cost,f1.id));
        }
    }
}

int main(){
    int x,y;
    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        graph[x].push_back(Floor((y-x)*5,y));
        graph[y].push_back(Floor((y-x)*5,x));
    }
    printf("%d\n", dijkstra());
}

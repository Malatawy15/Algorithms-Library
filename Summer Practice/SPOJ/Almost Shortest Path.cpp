#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define Inter pair<int, pair<int, int> >
#define mi(a,b,c) make_pair(a,make_pair(b,c))
#define Road pair<int, pair<int, pair<int, int> > >
#define cost first
#define id second.first
#define prev second.second.first
#define pcost second.second.second
#define mp(a,b,c,d) make_pair(c,make_pair(a,make_pair(b,c)))

int vis[501];
vector<int> pre[501];
int ee[501][501];
vector<Road> graph[501];

void trace_path(int node){
    if (node<0||vis[node])
        return;
    vis[node] = 1;
    for (int i=0;i<pre[node].size();i++){
        if (pre[node][i]<0)
            continue;
        ee[pre[node][i]][node] = 0;
        trace_path(pre[node][i]);
    }
}

int dijkstra(int s, int d, int flag){
    priority_queue<Road, vector<Road>, greater<Road> > pq;
    memset(vis, -1, sizeof vis);
    pq.push(mp(s,-1,0,0));
    int min = 1000000000;
    while(!pq.empty()){
        Road r = pq.top();
        pq.pop();
        if (r.cost>min)
            return -2;
        if (r.id==d){
            if (flag){
                if (min==1000000000)
                    min = r.cost;
            }
            else return r.cost;
        }
        if (vis[r.id]>-1){
            if (flag&&vis[r.id]==r.cost)
                pre[r.id].push_back(r.prev);
            continue;
        }
        if (flag)
            pre[r.id].push_back(r.prev);
        vis[r.id] = r.cost;
        for (int i=0;i<graph[r.id].size();i++){
            Road r1 = graph[r.id][i];
            if (ee[r.id][r1.id])
                pq.push(mp(r1.id,r.id,r1.cost+r.cost,r1.cost));
        }
    }
    return -1;
}

int main(){
    int N,M,x,y,z,s,d;
    scanf("%d %d",&N,&M);
    while(!(N==0&&M==0)){
        memset(ee,0,sizeof ee);
        scanf("%d %d",&s,&d);
        for (int i=0;i<M;i++){
            scanf("%d %d %d",&x,&y,&z);
            graph[x].push_back(mp(y,x,z,z));
            ee[x][y] = 1;
        }
        if (s!=d)
            x=dijkstra(s,d,1);
        if (x!=-1){
            memset(vis,0,sizeof(vis));
            trace_path(d);
            printf("%d\n",dijkstra(s,d,0));
        }
        else printf("-1\n");
        for (int i=0;i<N;i++){
            graph[i].clear();
            pre[i].clear();
        }
        scanf("%d %d",&N,&M);
    }
}



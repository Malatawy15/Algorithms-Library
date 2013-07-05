#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Road pair<int, pair<int, int> >
#define cost first
#define used second.first
#define id second.second
#define mp(a,b,c) make_pair(b,make_pair(c,a))

vector<Road> graph[10002];
int vis[10002][2];

int dijkstra(int s, int t){
    memset(vis,0,sizeof vis);
    priority_queue<Road, vector<Road>, greater<Road> > pq;
    pq.push(mp(s,0,0));
    while(!pq.empty()){
        Road r = pq.top();
        pq.pop();
        if (r.id==t)
            return r.cost;
        if (vis[r.id][r.used])
            continue;
        vis[r.id][r.used] = 1;
        for (int i=0;i<graph[r.id].size();i++){
            Road r1 = graph[r.id][i];
            if (r1.used&&r.used)
                continue;
            pq.push(mp(r1.id,r.cost+r1.cost,r.used|r1.used));
        }
    }
    return -1;
}

int main(){
    int t,N,M,K,S,T,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d",&N,&M,&K,&S,&T);
        for (int i=0;i<M;i++){
            scanf("%d %d %d",&x,&y,&z);
            graph[x].push_back(mp(y,z,0));
        }
        for (int i=0;i<K;i++){
            scanf("%d %d %d",&x,&y,&z);
            graph[x].push_back(mp(y,z,1));
            graph[y].push_back(mp(x,z,1));
        }
        printf("%d\n",dijkstra(S,T));
        for (int i=1;i<=N;i++)
            graph[i].clear();
    }
}

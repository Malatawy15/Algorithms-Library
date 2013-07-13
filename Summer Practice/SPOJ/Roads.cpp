#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Node pair<int, pair<int, int> >
#define cost first
#define toll second.first
#define id second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

int N, M, K;

vector<Node> graph[102];
int vis[102];

int dijkstra(){
    memset(vis,-1,sizeof vis);
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(mp(0,0,1));
    while(!pq.empty()){
        Node n = pq.top();
        pq.pop();
        if (n.toll>K)
            continue;
        if (n.id==N)
            return n.cost;
        if (vis[n.id]!=-1&&n.toll>=vis[n.id])
            continue;
        vis[n.id] = n.toll;
        for (int i=0;i<graph[n.id].size();i++)
            pq.push(mp(graph[n.id][i].cost+n.cost,graph[n.id][i].toll+n.toll,graph[n.id][i].id));
    }
    return -1;
}

int main(){
    int t,v,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&K,&N,&M);
        for (int i=0;i<M;i++){
            scanf("%d %d %d %d",&x,&y,&v,&z);
            graph[x].push_back(mp(v,z,y));
        }
        printf("%d\n", dijkstra());
        for (int i=0;i<=N;i++)
            graph[i].clear();
    }
}

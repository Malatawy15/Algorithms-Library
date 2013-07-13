#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Node pair<int, int>
#define cost first
#define id second

int N, M;

vector<Node> graph[1000002];
vector<Node> graphT[1000002];
int vis[1000002];

int dijkstra(int flag){
    memset(vis,0,sizeof vis);
    int sum = 0, count = 0;
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(Node(0,1));
    while(!pq.empty()){
        Node n = pq.top();
        pq.pop();
        if (vis[n.id])
            continue;
        vis[n.id] = 1;
        count++;
        sum+=n.cost;
        if (count==N)
            return sum;
        if (flag)
            for (int i=0;i<graph[n.id].size();i++)
                pq.push(Node(graph[n.id][i].cost+n.cost,graph[n.id][i].id));
        else
            for (int i=0;i<graphT[n.id].size();i++)
                pq.push(Node(graphT[n.id][i].cost+n.cost,graphT[n.id][i].id));
    }
}

int main(){
    int t,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&N,&M);
        for (int i=0;i<M;i++){
            scanf("%d %d %d",&x,&y,&z);
            graph[x].push_back(Node(z,y));
            graphT[y].push_back(Node(z,x));
        }
        printf("%d\n",dijkstra(0)+dijkstra(1));
        for (int i=0;i<=N;i++){
            graph[i].clear();
            graphT[i].clear();
        }
    }
}

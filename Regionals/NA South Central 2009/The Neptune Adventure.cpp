#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define Edge pair<int, int>
#define time first
#define id second

int N, S, D, CN;
vector<Edge> graph[101];
vector<int> floodings;
int flood[101];
int vis[101][101];

int dij(){
	memset(vis,0,sizeof vis);
	sort(floodings.begin(), floodings.end());
	int ind = 0;
    S--;D--;
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    pq.push(Edge(0,S));
    while(!pq.empty()){
        Edge e = pq.top();
        while(ind<floodings.size()&&e.time>=floodings[ind])
        	ind++;
        pq.pop();
        if (flood[e.id]<e.time)
            continue;
        if (e.id==D)
            return e.time;
        if (flood[e.id]<=e.time)
            continue;
        if (vis[e.id][ind])
            continue;
        vis[e.id][ind]=1;
        for (int i=0;i<graph[e.id].size();i++)
        	if (e.time+graph[e.id][i].time<=flood[e.id]&&(e.time+graph[e.id][i].time<=flood[graph[e.id][i].id]))
            pq.push(Edge(e.time+graph[e.id][i].time, graph[e.id][i].id));
    }
    return -1;
}

int main(){
    freopen("1.in.txt","r",stdin);
    freopen("1.txt","w",stdout);
    int t,x;
    scanf("%d", &t);
    for (CN=1;CN<=t;CN++){
    	floodings.clear();
        scanf("%d %d %d", &N, &S, &D);
        //printf("CASE #%d: %d %d %d\n",CN,N,S,D);
        for (int i=0;i<N;i++)
            graph[i].clear();
        for (int i=0;i<N;i++){
            scanf("%d", &flood[i]);
            if (!flood[i])
            	flood[i] = 1000000000;
            floodings.push_back(flood[i]);
            for (int j=0;j<N;j++){
                scanf("%d", &x);
                if (x)
                	graph[i].push_back(Edge(x,j));
            }
        }
        x = dij();
        if (x==-1)
            printf("GENE HACKMAN\n");
        else printf("%d\n",x);
    }
}

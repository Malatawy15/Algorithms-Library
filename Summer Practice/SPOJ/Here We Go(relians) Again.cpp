#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define Road pair<int, int>
#define cost first
#define id second

vector<Road> city [450];
int vis[450];

int dij(int d){
    priority_queue<Road, vector<Road>, greater<Road> > pq;
    memset(vis, 0, sizeof vis);
    pq.push(Road(0,0));
    while(!pq.empty()){
        Road r = pq.top();
        pq.pop();
        if (r.id==d)
            return r.cost;
        if (vis[r.id])
            continue;
        vis[r.id] = 1;
        for(int i=0;i<city[r.id].size();i++){
            Road r1 = city[r.id][i];
            pq.push(Road(r1.cost+r.cost, r1.id));
        }
    }
    return -1;
}

int main(){
    int N, M, x, off = 0;
    char c;
    int pre [10];
    for (int i=1;i<10;i++)
        pre[i] = 2520/i;
    scanf("%d %d", &N, &M);
    while(!(!N&&!M)){
    	off = 0;
        for (int i=0;i<N;i++,off+=(M+1)){
            for (int j=0;j<M;j++){
                scanf("%d",&x);
                scanf("%c",&c);
                scanf("%c",&c);
                if (x==0)
                	continue;
                if (c=='*') city[j+off].push_back(Road(pre[x],j+1+off)), city[j+off+1].push_back(Road(pre[x],j+off));
                else if (c=='>') city[j+off].push_back(Road(pre[x],j+1+off));
                else if (c=='<') city[j+off+1].push_back(Road(pre[x],j+off));
            }
            for (int j=0;j<=M;j++){
                scanf("%d",&x);
                scanf("%c",&c);
                scanf("%c",&c);
                if (x==0)
                	continue;
                if (c=='*') city[j+off].push_back(Road(pre[x],j+1+off+M)), city[j+off+1+M].push_back(Road(pre[x],j+off));
                else if (c=='v') city[j+off].push_back(Road(pre[x],j+1+off+M));
                else if (c=='^') city[j+off+1+M].push_back(Road(pre[x],j+off));
            }
        }
        for (int j=0;j<M;j++){
                scanf("%d",&x);
                scanf("%c",&c);
                scanf("%c",&c);
                if (x==0)
                	continue;
                if (c=='*') city[j+off].push_back(Road(pre[x],j+1+off)), city[j+off+1].push_back(Road(pre[x],j+off));
                else if (c=='>') city[j+off].push_back(Road(pre[x],j+1+off));
                else if (c=='<') city[j+off+1].push_back(Road(pre[x],j+off));
        }
        x = dij((N+1)*(M+1)-1);
        if (x==-1)
            printf("Holiday\n");
        else printf("%d blips\n",x);
        for (int i=0;i<450;i++)
            city[i].clear();
        scanf("%d %d", &N, &M);
    }
}

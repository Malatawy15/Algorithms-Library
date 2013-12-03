#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Pair pair<long long, int>
#define cost first
#define id second

int N;
long long vals [300010];
int vis [300010];

long long dij(){
    memset(vis, 0, sizeof vis);
    int s = 1, d = N*3-2;
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    pq.push(Pair(vals[s],s));
    while(!pq.empty()){
        Pair p = pq.top();
        pq.pop();
        if (p.id==d)
            return p.cost;
        if (vis[p.id])
        //if (vis[p.id]!=-1&&vis[p.id]<p.cost)
            continue;
        vis[p.id] = 1;
        int nn;
        long long nv = 0LL;
        if (p.id%3==0){
            nn = p.id+1;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
            if (!vis[nn])        pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
            nn = p.id+3;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
            nn = p.id+4;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
        }
        if (p.id%3==1){
            nn = p.id+1;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
            nn = p.id+2;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
            nn = p.id+3;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
            nn = p.id+4;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
        }
        if (p.id%3==2){
            nn = p.id+2;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                    if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
            nn = p.id+3;
            if (nn<3*N){
                nv = p.cost+vals[nn];
                //if (vis[nn]==-1||vis[nn]>nv)
                if (!vis[nn])pq.push(Pair(nv,nn));//, vis[nn] = nv;
            }
        }
    }
}

int main(){
    int n = 1;
    scanf("%d", &N);
    while(N){
        for (int i=0;i<3*N;i++)
            scanf("%lld", &vals[i]);
        printf("%d. %lld\n", n++, dij());
        scanf("%d", &N);
    }
}

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define Road pair<int, pair<int, int> >
#define risk first
#define time second.first
#define id second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int N, T;
int risks[101][101];
int times[101][101];
int vis[101];

void dij(){
    priority_queue<Road, vector<Road>, greater<Road> > pq;
    memset(vis,-1,sizeof vis);
    pq.push(mp(0,0,0));
    while(!pq.empty()){
        Road r = pq.top();
        pq.pop();
        if (r.time>T)
            continue;
        if (r.id==N-1){
            printf("%d %d\n", r.risk, r.time);
            return;
        }
        if (vis[r.id]!=-1&&vis[r.id]<=r.time)
            continue;
        vis[r.id] = r.time;
        for (int i=0;i<N;i++)
            if (i!=r.id)
                pq.push(mp(r.risk+risks[r.id][i],r.time+times[r.id][i],i));
    }
    printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &T);
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                scanf("%d", &times[i][j]);
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                scanf("%d", &risks[i][j]);
        dij();
    }
}

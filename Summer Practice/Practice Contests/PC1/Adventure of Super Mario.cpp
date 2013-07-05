#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;
#define Road pair<int, int>
#define Node pair<int, pair<int, pair<int, int> > >
#define cost first
#define id second.first
#define remK second.second.first
#define remL second.second.second
#define mp(a,b,c,d) make_pair(a, make_pair(b, make_pair(c,d)))

vector<Road> world[120];
int vis[102][11][510];
int A, B, M, L, K;

int dijkstra(){
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    memset(vis, 0, sizeof vis);
    int flag = 0;
    if (K>0)
        pq.push(mp(0,A+B,K,L));
    else pq.push(mp(0,A+B,K,0));
    while(!pq.empty()){
        Node n = pq.top();
        pq.pop();
        if (n.id==1)
            return n.cost;
        if (vis[n.id][n.remK][n.remL])
            continue;
        printf("%d %d %d %d\n", n.id, n.cost, n.remK, n.remL);
        vis[n.id][n.remK][n.remL] = 1;
        for (int i=0;i<world[n.id].size();i++){
            Road nn = world[n.id][i];
            if (!flag&&n.id==A+B){
                if (n.remL>=nn.second){
                    pq.push(mp(n.cost,nn.first,n.remK,n.remL-nn.second));
                    pq.push(mp(n.cost+nn.second,nn.first,n.remK,L));
                }
                else if (n.remK>0){
                    pq.push(mp(n.cost+nn.second,nn.first,n.remK-1,L));
                    pq.push(mp(n.cost,nn.first,n.remK-1,L-nn.second));
                }
                else pq.push(mp(n.cost+nn.second,nn.first,0,0));
                flag = 1;
                continue;
            }
            if (n.id>A){
                if (n.remK>0){
                    pq.push(mp(n.cost,nn.first,n.remK-1,L-nn.second));
                    pq.push(mp(n.cost+nn.second,nn.first,n.remK-1,L));
                }
                else pq.push(mp(n.cost+nn.second,nn.first,0,0));
            }
            else{
                if (n.remL>=nn.second)
                    pq.push(mp(n.cost,nn.first,n.remK,n.remL-nn.second));
                else if (n.remK>0){
                    pq.push(mp(n.cost+nn.second,nn.first,n.remK-1,L));
                    pq.push(mp(n.cost,nn.first,n.remK-1,L-nn.second));
                }
                else pq.push(mp(n.cost+nn.second,nn.first,0,0));
            }
        }
    }
    return -1;
}

int main(){
    int t,x,y,z;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d %d %d", &A, &B, &M, &L, &K);
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &x, &y, &z);
            world[x].push_back(Road(y,z));
            world[y].push_back(Road(x,z));
        }
        printf("%d\n", dijkstra());
    }
}

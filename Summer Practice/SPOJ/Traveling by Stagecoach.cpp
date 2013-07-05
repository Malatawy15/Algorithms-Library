#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Node pair<int, int>
#define City pair<double, pair<int, int> >
#define cost first
#define bitmask second.first
#define id second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int vis [33][300];
int tickets[8];
vector<Node> graph[33];

int n,m,p,a,b;

int use_ticket(int total, int ticket){
    return total|(1<<ticket);
}

int is_used(int total, int ticket){
    return (total&(1<<ticket))>0;
}

void dijkstra(){
    memset(vis, 0, sizeof vis);
    priority_queue<City, vector<City>, greater<City> > pq;
    pq.push(mp(0,0,a));
    while (!pq.empty()){
        City c = pq.top();
        pq.pop();
        if (c.id==b){
            printf("%lf\n", c.cost);
            return;
        }
        if (vis[c.id][c.bitmask])
            continue;
        vis[c.id][c.bitmask] = 1;
        //printf("Bitmask: %d\n", c.bitmask);
        for (int i=0;i<graph[c.id].size();i++){
            for (int j=0;j<n;j++){
                if (!is_used(c.bitmask, j)){
                    //printf("%d passed\n", j);
                    pq.push(mp(c.cost+graph[c.id][i].second*1.0/tickets[j], use_ticket(c.bitmask,j), graph[c.id][i].first));
                }
            }
        }
    }
    printf("Impossible\n");
}

int main(){
    int x,y,z;
    scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    while(!(!n&&!m&&!p&&!a&&!b)){
        for (int i=0;i<n;i++)
            scanf("%d", &tickets[i]);
        for (int i=0;i<=m;i++)
            graph[i].clear();
        for (int i=0;i<p;i++){
            scanf("%d %d %d", &x, &y, &z);
            graph[x].push_back(Node(y,z));
            graph[y].push_back(Node(x,z));
        }
        dijkstra();
        scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    }
}

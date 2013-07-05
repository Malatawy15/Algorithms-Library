#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<map>

using namespace std;

#define Node pair<int, int>
#define id first
#define cost second

vector<int> graph[31];
map<int, int> m;

int vis[31];
int N;

int bfs(int s, int TTL){
    int counted = 0;
    memset(vis, 0, sizeof vis);
    queue<Node> q;
    q.push(Node(s, TTL));
    while(!q.empty()){
        Node n = q.front();
        q.pop();
        if (vis[n.id])
            continue;
        vis[n.id] = 1;
        counted++;
        if (n.cost==0)
            continue;
        for (int i=0;i<graph[n.id].size();i++){
            if (!vis[graph[n.id][i]])
                q.push(Node(graph[n.id][i], n.cost-1));
        }
    }
    return N-counted;
}

int main(){
    int NC, s, e, cases = 1;
    map<int,int>::iterator it;
    scanf("%d", &NC);
    while(NC){
        N = 0;
        while (NC--){
            scanf("%d %d", &s, &e);
            it = m.find(s);
            if (it==m.end()){
                m.insert(make_pair(s, N));
                s = N++;
            }
            else s = it->second;
            it = m.find(e);
            if (it==m.end()){
                m.insert(make_pair(e, N));
                e = N++;
            }
            else e = it->second;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
        /*printf("Graph:\n\n");
        for (int i=0;i<N;i++){
            printf("%d: ",i);
            for (int j=0;j<graph[i].size();j++){
                printf("%d ",graph[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");*/
        //printf("N: %d\n", N);
        scanf("%d %d", &s, &e);
        while(!(s==0&&e==0)){
            //printf("Query: %d %d\n", m.find(s)->second, e);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,bfs(m.find(s)->second,e), s, e);
            scanf("%d %d", &s, &e);
        }
        m.clear();
        for (int i=0;i<31;i++)
            graph[i].clear();
        scanf("%d", &NC);
    }
}

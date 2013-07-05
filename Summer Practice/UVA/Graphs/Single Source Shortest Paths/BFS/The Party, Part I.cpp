#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Person pair<int, int>
#define id first
#define cost second

int P, D, s, d, t;
vector<int> graph[1000];
int vis[1000];
int giovanni[1000];

void bfs(){
    queue<Person> q;
    q.push(make_pair(0,0));
    memset(vis, 0, sizeof vis);
    while(!q.empty()){
        Person p = q.front();
        q.pop();
        if (vis[p.id])
            continue;
        vis[p.id] = 1;
        giovanni[p.id] = p.cost;
        for (int i=0;i<graph[p.id].size();i++)
            q.push(make_pair(graph[p.id][i], p.cost+1));
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &P, &D);
        for (int i=0;i<P;i++)
            graph[i].clear();
        for (int i=0;i<D;i++){
            scanf("%d %d", &s, &d);
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        bfs();
        for (int i=1;i<P;i++)
            printf("%d\n", giovanni[i]);
        if (t)
            printf("\n");
    }
}

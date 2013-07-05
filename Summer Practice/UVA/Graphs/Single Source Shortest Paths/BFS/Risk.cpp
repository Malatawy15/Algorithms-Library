#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Country pair<int, int>
#define id first
#define cost second

vector<int> graph[21];

int vis[21];

int bfs(int sc, int ec){
    memset(vis,0,sizeof vis);
    queue<Country> q;
    q.push(Country(sc,0));
    while(!q.empty()){
        Country c = q.front();
        q.pop();
        if (vis[c.id])
            continue;
        if (c.id==ec)
            return c.cost;
        vis[c.id] = 1;
        for (int i=0;i<graph[c.id].size();i++){
            if (!vis[graph[c.id][i]])
                q.push(Country(graph[c.id][i], c.cost+1));
        }
    }
    return -1;
}

int main(){
    int n, d, s, e, set = 1;;
    while(scanf("%d", &n)>0){
        while(n--){
            scanf("%d", &d);
            graph[1].push_back(d);
            graph[d].push_back(1);
        }
        for (int i=2;i<20;i++){
            scanf("%d", &n);
            while(n--){
                scanf("%d", &d);
                graph[i].push_back(d);
                graph[d].push_back(i);
            }
        }
        scanf("%d", &n);
        printf("Test Set #%d\n",set++);
        while(n--){
            scanf("%d %d", &s, &e);
            if (s<10)
                printf(" %d to ",s);
            else printf("%d to ",s);
            if (e<10)
                printf(" %d: %d\n",e,bfs(s,e));
            else printf("%d: %d\n",e,bfs(s,e));
        }
        printf("\n");
        for (int i=1;i<=20;i++)
            graph[i].clear();
    }
}

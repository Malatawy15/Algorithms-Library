#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define Pos pair<int, int>

int N, S, F;
double L1, L2;

int vis [1001];
vector<int> graph[1001];
vector<pair<int, int> > pts;

void create_graph(){
    for (int i=0;i<N;i++)
        for (int j=i+1;j<N;j++){
            if (hypot(abs(pts[i].first-pts[j].first),abs(pts[i].second-pts[j].second))<=(L1+L2)){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
}

int bfs(){
    queue<Pos> q;
    memset(vis, 0, sizeof vis);
    q.push(make_pair(S,0));
    while(!q.empty()){
        Pos p = q.front();
        q.pop();
        if (p.first==F)
            return p.second;
        if (vis[p.first])
            continue;
        vis[p.first] = 1;
        for (int i=0;i<graph[p.first].size();i++)
            q.push(make_pair(graph[p.first][i],p.second+1));
    }
    return -1;
}

int main(){
    int t, xx, yy;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %lf %lf", &N, &S, &F, &L1, &L2);
        S--;F--;
        for (int i=0;i<N;i++){
            scanf("%d %d", &xx, &yy);
            pts.push_back(make_pair(xx,yy));
        }
        create_graph();
        int x = bfs();
        if (x==-1)
            printf("Impossible\n");
        else printf("%d\n", x);
        for (int i=0;i<N;i++)
            graph[i].clear();
        pts.clear();
    }
}

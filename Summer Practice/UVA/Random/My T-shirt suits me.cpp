#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

#define MAX_V 70
#define INF 1000000000

int N, M;
char inp[5];
int res[MAX_V][MAX_V], mf, f, s, t;
vi p;

void augment(int v, int minEdge){
    if (v==s){f = minEdge; return;}
    else if (p[v]!=-1){augment(p[v], min(minEdge, res[p[v]][v]));
                        res[p[v]][v]-=f; res[v][p[v]]+=f;}
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        scanf("%d %d", &N, &M);
        memset(res, 0, sizeof res);
        int tr = N/6;
        int indices[] = {0,tr,tr*2,tr*3,tr*4,tr*5};
        for (int i=tr*6;i<tr*6+M;i++){
            scanf("%s", inp);
            int ind;
            if (strcmp(inp,"XXL")==0) ind = indices[0];
            else if (strcmp(inp,"XL")==0) ind = indices[1];
            else if (strcmp(inp,"L")==0) ind = indices[2];
            else if (strcmp(inp,"M")==0) ind = indices[3];
            else if (strcmp(inp,"S")==0) ind = indices[4];
            else if (strcmp(inp,"XS")==0) ind = indices[5];
            res[i][ind] = 1;
            for (int j=ind;j<ind+tr;j++)
                res[i][j] = 1;
            scanf("%s", inp);
            if (strcmp(inp,"XXL")==0) ind = indices[0];
            else if (strcmp(inp,"XL")==0) ind = indices[1];
            else if (strcmp(inp,"L")==0) ind = indices[2];
            else if (strcmp(inp,"M")==0) ind = indices[3];
            else if (strcmp(inp,"S")==0) ind = indices[4];
            else if (strcmp(inp,"XS")==0) ind = indices[5];
            for (int j=ind;j<ind+tr;j++)
                res[i][j] = 1;
            res[tr*6+M][i] = 1;
        }
        for (int i=0;i<tr*6;i++){
            res[i][tr*6+M+1] = 1;
        }
        s = tr*6+M, t = tr*6+M+1;
        mf = 0;                                              // mf stands for max_flow
  while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
    f = 0;
    // run BFS, compare with the original BFS shown in Section 4.2.2
    vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
    p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;      // immediately stop BFS if we already reach sink t
      for (int v = 0; v < MAX_V; v++)                 // note: this part is slow
        if (res[u][v] > 0 && dist[v] == INF)
          dist[v] = dist[u] + 1, q.push(v), p[v] = u;
    }
    augment(t, INF);     // find the min edge weight `f' along this path, if any
    if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
    mf += f;                 // we can still send a flow, increase the max flow!
  }

  printf("%s\n", mf>=M?"YES":"NO");                              // this is the max flow value


    }
}

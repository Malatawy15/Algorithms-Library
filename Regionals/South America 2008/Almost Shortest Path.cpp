#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define Edge pair<int, pair<int, int> >
#define cst first
#define id second.first
#define ind second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int N, M, S, D;
int vis[501];
int vedge[10010];
vector<Edge > graph[501];
//vector<Edge > graphT[501];

struct Edges{
    int cost, eid;
    vector<int> edg;
    bool operator<(const Edges &e2)const{
        return cost>e2.cost;
    }
};

Edges mk_edg(int c, int d){
    Edges ne;
    ne.cost = c;
    ne.eid = d;
    //printf("MK_EDG: %d %d\n",ne.cost,ne.eid);
    return ne;
}

void dij1(){
    memset(vis,-1,sizeof vis);
    memset(vedge,0,sizeof vedge);
    priority_queue<Edges> pq;
    pq.push(mk_edg(0,S));
    int ms = 0, mini;
    while(!pq.empty()){
        Edges e1 = pq.top();
        pq.pop();
        //printf("EDG: %d %d\n",e1.eid,e1.cost);
        if (ms&&e1.cost>mini)
            return;
        if (e1.eid==D){
            if (ms){
                if (mini==e1.cost)
                    for (int i=0;i<e1.edg.size();i++)
                        vedge[e1.edg[i]] = 1;
                else return;
            }
            else{
                ms = 1;
                mini = e1.cost;
                for (int i=0;i<e1.edg.size();i++)
                    vedge[e1.edg[i]] = 1;
            }
        }
        if (vis[e1.eid]!=-1&&vis[e1.eid]<e1.cost)
            continue;
        vis[e1.eid] =  e1.cost;
        for (int i=0;i<graph[e1.eid].size();i++){
            Edge e = graph[e1.eid][i];
            Edges e2 = mk_edg(e1.cost+e.cst,e.id);
            e2.edg = vector<int>(e1.edg);
            e2.edg.push_back(e.ind);
            pq.push(e2);
        }
    }
    /*for (int i=0;i<N;i++){
        graphT.clear();
        for (int j=0;j<graph[i].size();j++)
            if (!vedge[graph[i][j].ind])
                graphT.push_back(graph[i][j]);
    }*/
}

int dij2(){
    memset(vis,0,sizeof vis);
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    pq.push(mp(0,S,0));
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if (e.id==D)
            return e.cst;
        if (vis[e.id])
            continue;
        vis[e.id] = 1;
        for (int i=0;i<graph[e.id].size();i++){
            Edge ne = graph[e.id][i];
            if (!vedge[ne.ind])
                pq.push(mp(e.cst+ne.cst,ne.id,0));
        }
    }
    return -1;
}

int main(){
    int x,y,z;
    scanf("%d %d", &N, &M);
    while(!(!N&&!M)){
        scanf("%d %d", &S, &D);
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &x,&y,&z);
            graph[x].push_back(mp(z,y,i));
        }
        dij1();
        printf("%d\n",dij2());
        for (int i=0;i<N;i++)
            graph[i].clear();
        scanf("%d %d", &N, &M);
    }
}

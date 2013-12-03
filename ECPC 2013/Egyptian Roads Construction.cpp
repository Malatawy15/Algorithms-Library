#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Edge pair<int, int>
#define cost first
#define index second

int NN, M;
vector<vector<Edge> >sets_graph;
vector<int> sets_cost;
int edges[100001][3];


void dfs(int node, int csf){
    sets_cost[node] = csf;
    for (int i=0;i<sets_graph[node].size();i++){
        dfs(sets_graph[node][i].index, csf+sets_graph[node][i].cost);
    }
}


struct disjoint_sets{
    int N, size;
    vector<int> pset;
    vector<int> set_size;
    vector<int> set_index;

    disjoint_sets(int n){
        N = n;
        size = N;
        set_size = vector<int>(N,1);
        pset = vector<int>(N);
        for (int i=0;i<N;i++){
            pset[i] = i;
            set_index.push_back(i);
            sets_graph.push_back(vector<Edge>());
        }
    }

    int count_sets(){
        return size;
    }

    int find_set(int node){
        if (pset[node]==node)
            return node;
        else return pset[node] = find_set(pset[node]);
    }

    void union_set(int n1, int n2, int cst){
        int p1 = find_set(n1), p2 = find_set(n2), i1 = set_index[p1], i2 = set_index[p2], s1 = set_size[p1], s2 = set_size[p2];
        pset[p1] = p2;
        if (p1!=p2)
            size--;
        set_size[p2]+=s1;
        sets_graph.push_back(vector<Edge>());
        sets_graph[N].push_back(Edge(cst*s2,i1));
        sets_graph[N].push_back(Edge(cst*s1,i2));
        set_index[p2] = N++;
    }

    void fill(){
        sets_cost = vector<int> (N,0);
        dfs(N-1,0);
    }

};

vector<Edge> edg;


void kruskal(){
    disjoint_sets ds(NN);
    sort(edg.begin(), edg.end());
    for (int i=0;i<edg.size();i++){
        int u = edges[edg[i].index][0], v = edges[edg[i].index][1];
        if (ds.find_set(u)!=ds.find_set(v)){
            ds.union_set(u,v,edg[i].cost);
        }
        if (ds.count_sets()==1)
            break;
    }
    ds.fill();
}

int main(){
    freopen("road.in", "r", stdin);
    int t, cn = 1;
    scanf("%d", &t);
    while(t--){
        edg.clear();
        sets_graph.clear();
        scanf("%d %d", &NN, &M);
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
            edges[i][0]--;
            edges[i][1]--;
            edg.push_back(Edge(edges[i][2],i));
        }
        kruskal();
        printf("Case %d:\n", cn++);
        for (int i=0;i<NN;i++){
            printf("%d\n", sets_cost[i]);
        }
    }
}

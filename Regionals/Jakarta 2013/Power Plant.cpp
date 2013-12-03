#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, K;

#define Edge pair<int, pair<int, int> >
#define cost first
#define n1 second.first
#define n2 second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

vector < Edge > edges;
vector<int> is_plant;


struct disjoint_sets{
    int N, size;
    vector<int> pset;
    vector<int> has_plant;
    disjoint_sets(int n){
        N = n;
        size = N;
        pset = vector<int> (n,-1);
        has_plant = vector<int> (n,0);
        for (int i=0;i<N;i++)
            has_plant[i] = is_plant[i];
    }

    int find_set(int s){
        if (pset[s]==-1)
            return s;
        return pset[s] = find_set(pset[s]);
    }

    void union_set(int s1, int s2){
        int p1 = find_set(s1), p2 = find_set(s2);
        pset[p1] = p2;
        has_plant[p2]|=has_plant[p1];
        size--;
    }

    int count_sets(){
        return size;
    }

};

int kruskal(){
    sort(edges.begin(), edges.end());
    int tc = 0;
    disjoint_sets ds(N);
    for (int i=0;i<edges.size();i++){
        int s1 = edges[i].n1, s2 = edges[i].n2;
        int p1 = ds.find_set(s1), p2 = ds.find_set(s2);
        if (is_plant[s1]&&is_plant[s2])
            continue;
        if (ds.count_sets()==K)
            return tc;
        if (p1!=p2){
            if (!(ds.has_plant[p1]&&ds.has_plant[p2])){
                ds.union_set(s1,s2);
                tc+=edges[i].cost;
            }
        }
    }
    //printf("FALL\n");
    return tc;
}

int main(){
    int t, a,b,c, cn = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &N, &M, &K);
        is_plant = vector<int> (N,0);
        edges.clear();
        for (int i=0;i<K;i++){
            scanf("%d", &a);
            a--;
            is_plant[a] = 1;
        }
        for (int i=0;i<M;i++){
            scanf("%d %d %d",&a,&b,&c);
            a--;b--;
            edges.push_back(mp(c,a,b));
        }
        //printf("INPUT READ\n");
        printf("Case #%d: %d\n", cn++,kruskal());
    }
}

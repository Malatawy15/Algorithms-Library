#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Pair pair<int, int>

struct disjoint_sets{
    int N, size;
    vector<int> pset;
    vector<int> rank;
    vector<int> set_size;

    disjoint_sets(int n){
        N = n;
        size = N;
        rank = vector<int>(N,0);
        set_size = vector<int>(N,1);
        pset = vector<int>(N);
        for (int i=0;i<N;i++){
            pset[i] = i;
        }
    }

    int find_set(int n){
        if (pset[n]==n){
            return n;
        }
        return pset[n] = find_set(pset[n]);
    }

    int union_set(int i, int j){
        if ((i==pset[i]) && (j==pset[j])){
            if (i==j){
                return i;
            }
            size--;
            if (rank[i]>rank[j]){
                set_size[i] += set_size[j];
                return pset[j] = i;
            }
            else if (rank[j]>rank[i]){
                set_size[j] += set_size[i];
                return pset[i] = j;
            }
            else {
                rank[j]++;
                set_size[j] += set_size[i];
                return pset[i] = j;
            }
        }
        return pset[i] = pset[j] = union_set(pset[i], pset[j]);
    }

    int get_size(int n){
        return set_size[find_set(n)];
    }

    pair<int, int> max_set(){
        int maxN = -1, maxI, curS;
        for (int i=0;i<N;i++){
            curS = get_size(i);
            if (curS>maxN){
                maxN = curS;
                maxI = i;
            }
        }
        return make_pair(maxI, maxN);
    }

    int count(){
        return size;
    }
};

vector<Pair> edg;
int edges[25010][2];

int main(){
    int n,m,x,y,z;
    scanf("%d %d", &n,&m);
    while(!(!n&&!m)){
        edg.clear();
        for (int i=0;i<m;i++){
            scanf("%d %d %d",&edges[i][0],&edges[i][1],&z);
            edg.push_back(Pair(z,i));
        }
        sort(edg.begin(), edg.end());
        disjoint_sets ds (n);
        int f = 0;
        for (int i=0;i<m;i++){
            int ind = edg[i].second;
            if (ds.find_set(edges[ind][0])!=ds.find_set(edges[ind][1])){
                ds.union_set(edges[ind][0],edges[ind][1]);
            }
            else {
                if (!f){
                    f = 1;
                    printf("%d",edg[i].first);
                }
                else printf(" %d",edg[i].first);
            }
        }
        if (!f){
            printf("forest");
        }
        printf("\n");
        scanf("%d %d", &n,&m);
    }
}

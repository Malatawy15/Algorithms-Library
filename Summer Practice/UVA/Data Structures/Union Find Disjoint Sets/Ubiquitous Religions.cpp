#include<stdio.h>
#include<vector>

using namespace std;

struct disjoint_sets{
    int N, size;
    vector<int> pset;
    vector<int> rank;

    disjoint_sets(int n){
        N = n;
        size = N;
        rank = vector<int>(N,0);
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
                return pset[j] = i;
            }
            else if (rank[j]>rank[i]){
                return pset[i] = j;
            }
            else {
                rank[j]++;
                return pset[i] = j;
            }
        }
        return pset[i] = pset[j] = union_set(pset[i], pset[j]);
    }

    int count(){
        return size;
    }
};

int main(){
    int n, m, x, y, cn = 1;
    scanf("%d %d", &n, &m);
    while(!(!n&&!m)){
        disjoint_sets ds (n);
        for (int i=0;i<m;i++){
            scanf("%d %d", &x, &y);
            x--;
            y--;
            ds.union_set(x,y);
        }
        printf("Case %d: %d\n", cn++, ds.count());
        scanf("%d %d", &n, &m);
    }
}

#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

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

int main(){
    double pos[1001][2];
    int t, n;
    double d;
    scanf("%d", &t);
    for(int cn = 1;cn<=t;cn++){
        scanf("%d %lf", &n, &d);
        disjoint_sets ds (n);
        for (int i=0;i<n;i++)
            scanf("%lf %lf", &pos[i][0], &pos[i][1]);
        for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++){
            if (hypot(fabs(pos[i][0]-pos[j][0]), fabs(pos[i][1]-pos[j][1]))<=d){
                ds.union_set(i,j);
            }
        }
        printf("Case %d: %d\n", cn,ds.count());
    }
}

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

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
    int t, n, m, x, y;
    char buf[50];
    gets(buf);
    sscanf(buf,"%d", &t);
    gets(buf);
    while(t--){
        gets(buf);
        sscanf(buf,"%d %d", &n, &m);
        gets(buf);
        int saw[n][m];
        memset(saw,0,sizeof saw);
        while(buf[0]!='\0'&&!feof(stdin)){
            sscanf(buf,"%d %d", &x, &y);
            x--;y--;
            saw[x][y] = 1;
            gets(buf);
        }
        disjoint_sets ds(n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (ds.find_set(i)!=ds.find_set(j)){
                    int f = 1;
                    for (int k=0;k<m;k++){
                        if (saw[i][k]!=saw[j][k]){
                            f = 0;
                            break;
                        }
                    }
                    if (f)
                        ds.union_set(i,j);
                }
        printf("%d\n", ds.count());
        if (t)
            printf("\n");
    }
}

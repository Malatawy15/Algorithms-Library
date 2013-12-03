#include<stdio.h>
#include<vector>
#include<map>
#include<string>

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
    map<string, int> mp;
    map<string, int>::iterator it;
    char buf[1000];
    int t,n,nn,x,y;
    string in;
    scanf("%d", &t);
    while(t--){
        mp.clear();
        scanf("%d", &n);
        disjoint_sets ds (n<<1);
        nn = 0;
        for (int i=0;i<n;i++){
            scanf("%s", buf);
            in = string(buf);
            it = mp.find(in);
            if (it==mp.end()){
                x = nn++;
                mp.insert(make_pair(in,x));
            }
            else x = it->second;
            scanf("%s", buf);
            in = string(buf);
            it = mp.find(in);
            if (it==mp.end()){
                y = nn++;
                mp.insert(make_pair(in,y));
            }
            else y = it->second;
            ds.union_set(x,y);
            printf("%d\n",ds.get_size(x));
        }
    }
}

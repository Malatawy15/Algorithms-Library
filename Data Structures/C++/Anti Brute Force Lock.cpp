#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
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

int conv(int a, int b){
    int x,y;
    x = min(a,b);
    y = max(a,b);
    return min(y-x,x+10-y);
}

int edg_weight(string a, string b){
    return conv(a[0]-'0',b[0]-'0')+conv(a[1]-'0',b[1]-'0')+conv(a[2]-'0',b[2]-'0')+conv(a[3]-'0',b[3]-'0');
}

int edges[300000][2];

int main(){
    string init = "0000";
    string in;
    vector<string> locks;
    vector<Pair> edg;
    int n, t;
    cin>>t;
    while(t--){
        edg.clear();
        locks.clear();
        cin>>n;
        n++;
        locks.push_back(init);
        for (int i=1;i<n;i++){
            cin>>in;
            locks.push_back(in);
        }
        int ind = 0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++){
                edges[ind][0] = i;
                edges[ind][1] = j;
                edg.push_back(Pair(edg_weight(locks[i],locks[j]),ind));
                ind++;
            }
        sort(edg.begin(),edg.end());
        int sum = 0,used = 0;
        disjoint_sets ds(n);
        for (int i=0;i<edg.size();i++){
            if (ds.count()==1)
                break;
            int ii = edg[i].second;
            if (ds.find_set(edges[ii][0])!=ds.find_set(edges[ii][1])){
                if (edges[ii][0]==0)
                    if (used) continue;
                    else used = 1;
                sum+=edg[i].first;
                ds.union_set(edges[ii][0],edges[ii][1]);
            }
        }
        printf("%d\n", sum);
    }
}

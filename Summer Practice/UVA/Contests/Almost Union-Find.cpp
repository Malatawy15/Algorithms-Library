#include<stdio.h>
#include<string.h>
#include<vector>
#include <algorithm>

using namespace std;

int pset[100010];
int vis[100010];
vector<int> children[100010];
pair<int, int> sums[100010];

int find_set (int p){
    return pset[p]==p?p: find_set(pset[p]);
}

void union_set(int p, int q){
    //int parent = find_set(p);
    int p1 = find_set(p), p2 = find_set(q);
    if (p1==p2){
        //printf("Matching Parents Found\n");
        return;
    }
    children[p2].push_back(p1);
    pset[p1] = p2;
    int nc = sums[p2].first+sums[p1].first, ns = sums[p2].second+sums[p1].second;
    sums[p2] = make_pair(nc, ns);
}

void move_to_set(int p, int q){
    int p1 = find_set(p), p2 = find_set(q);
  //  printf("Parents: %d %d\n", p1, p2);
    if (p1==p2)
        return;
    if (pset[p]==p){
        //printf("PSET == P\n");
        for (int i = 0;i<children[p].size();i++){
            pset[children[p][i]] = children[p][0];
            if (i!=0)
                children[children[p][0]].push_back(children[p][i]);
        }
        if (children[p].size()!=0){
            sums[children[p][0]] = make_pair(sums[p].first-1, sums[p].second-p);
        }
        //printf("END\n");
    }
    else {
        vector<int>::iterator it;
        it = find (children[pset[p]].begin(), children[pset[p]].end(), p);
        children[pset[p]].erase(it);
        //printf("PSET != P %d\n", children[p][0]);
        for (int i = 0;i<children[p].size();i++){
            pset[children[p][i]] = p1;
            children[p1].push_back(children[p][i]);
        }
        //printf("END\n");
        sums[p1] = make_pair(sums[p1].first-1, sums[p1].second-p);
    }
    sums[p2] = make_pair(sums[p2].first+1, sums[p2].second+p);
    children[p].clear();
    pset[p] = p2;
    children[p2].push_back(p);
}

pair<int, int> dfs(int p){
    if (vis[p])
        return make_pair(0, 0);
    //printf("DFS: %d\n", p);
    vis[p] = 1;
    pair<int, int> ret;
    int count = 1, sum = p;
    for (int i =0;i<children[p].size();i++){
        ret = dfs(children[p][i]);
        count+= ret.first;
        sum+= ret.second;
    }
    return make_pair(count, sum);
}

pair<int, int> count_elements(int p){
    //memset(vis, 0, sizeof vis);
    return sums[find_set(p)];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int n,m, op, i1, i2;
    pair<int, int> c;
    while (scanf("%d %d", &n, &m)>0){
        for (int i = 1;i<=n;i++){
            pset[i] = i;
            children[i].clear();
            sums[i] = make_pair(1, i);
        }
        for (int i =0;i<m;i++){
            scanf("%d", &op);
            switch(op){
                case 1: scanf("%d %d", &i1, &i2); union_set(i1, i2); break;
                case 2: scanf("%d %d", &i1, &i2); move_to_set(i1, i2); break;
                case 3: scanf("%d", &i1); c = count_elements(i1); printf("%d %d\n", c.first, c.second); break;
            }
        }
    }
}

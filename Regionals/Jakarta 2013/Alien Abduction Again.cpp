#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Pair pair<pair<int, int> , pair<int, int> >
#define A first.first
#define B first.second
#define C second.first
#define D second.second
#define mp(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))

struct segment_tree{
    static const int inf = 0x7fffffff;
    int N;
    vector<int> vals;
    vector<int> tree;
    vector<Pair> lazy_sum;
    vector<int> lazy_set;
    vector<int> flag;

    segment_tree(int n, int value, int type){ //0-rmq, 1-rsq
        nearest(n);
        vals = vector<int>(n,value);
        tree = vector<int>(N<<1,0);
        lazy_set = vector<int>(N<<1,0);
        lazy_sum = vector<Pair>(N<<1, mp(0,0,0,0));
        flag = vector<int>(N<<1,0);
    }

    void nearest(int n){
        N = 1;
        while(N<n){
            N<<=1;
        }
    }

    void build_rmq(int node, int s, int e, int n){
        if (s>e){
            return;
        }
        if (s==e){ //leaf node
            if (s>n){
                tree[node] = inf;
            }
            else {
                tree[node] = vals[s-1];
            }
            return;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        build_rmq(ln, s, mid, n);
        build_rmq(rn, mid+1, e, n);
        tree[node] = min(tree[ln],tree[rn]);
    }

    int rsq_query(int node, int s, int e, int i, int j){
        prepare(node,s,e);
        if (s>e||s>j||e<i){
            return 0;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        if (s>=i&&e<=j){
            return tree[node];
        }
        return rsq_query(ln,s,mid,i,j)+rsq_query(rn,mid+1,e,i,j);
    }

    void update(int s, int e, int value){
        return update_range(1,1,N,s,e,value);
    }

    void update_range(int node, int s, int e, int i, int j,int value){
        prepare(node,s,e);
        if (s>e||s>j||e<i){
            return;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        if (s>=i&&e<=j){
            flag[node] = 1;
            lazy_set[node] = value;
            lazy_sum[node] = mp(0,0,0,0);
            prepare(node,s,e);
            return;
        }
        update_range(ln,s,mid,i,j,value);
        update_range(rn,mid+1,e,i,j,value);
        tree[node] = min(tree[ln],tree[rn]);
    }

    void prepare(int node, int s, int e){
        int ln = node<<1, rn = (node<<1)+1;
        if (flag[node]){
            tree[node] = lazy[node];
            if (s!=e){
                lazy_sum[ln] = lazy_sum[node];
                lazy_set[ln] = lazy_set[node];
                flag[ln] = 1;
                lazy_sum[rn] = lazy_sum[node];
                lazy_set[rn] = lazy_set[node];
                flag[rn] = 1;
            }
            flag[node] = 0;
        }
    }

};



int main(){
}

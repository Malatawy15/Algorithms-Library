#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct segment_tree{
    static const int inf = 0x7fffffff;
    int N;
    vector<int> vals;
    vector<int> tree;
    vector<int> lazy;
    vector<int> flag;

    segment_tree(int n, vector<int> v, int type){ //0-rmq, 1-rsq
        nearest(n);
        vals = vector<int>(v);
        lazy = vector<int>(N<<1,0);
        flag = vector<int>(N<<1,0);
        if (type){
            build_rsq(1,1,N,n);
        }
        else {
            build_rmq(1,1,N,n);
        }
    }

    segment_tree(int n, int value, int type){ //0-rmq, 1-rsq
        nearest(n);
        vals = vector<int>(n,value);
        lazy = vector<int>(N<<1,0);
        flag = vector<int>(N<<1,0);
        if (type){
            build_rsq(1,1,N,n);
        }
        else {
            build_rmq(1,1,N,n);
        }
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

    void build_rsq(int node, int s, int e, int n){
        if (s>e){
            return;
        }
        if (s==e){ //leaf node
            if (s>n){
                tree[node] = 0;
            }
            else {
                tree[node] = vals[s-1];
            }
            return;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        build_rsq(ln, s, mid, n);
        build_rsq(rn, mid+1, e, n);
        tree[node] = tree[ln]+tree[rn];
    }

    int get_index(int index){ // 1-based index
        return tree[N+index-1];
    }

};



int main(){
    /*
    int n;
    scanf("%d", &n);
    init(n);
    build(1, 1, N);
    update(4, 0);
    printf("%d\n", query(1,1));
    printf("%d\n", query(2,2));
    printf("%d\n", query(3,3));
    printf("%d\n", query(1,2));
    printf("%d\n", query(2,3));
    printf("%d\n", query(1,3));
    */
}

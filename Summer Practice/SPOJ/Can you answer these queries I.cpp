#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct tree_node{
    int sum;
    int pre;
    int suf;
    int ans;
    tree_node(int a,int b, int c, int d){
        sum = a;
        pre = b;
        suf = c;
        ans = d;
    }
};

struct segment_tree{
    static const int inf = 100000000;
    int N;
    vector<int> vals;
    vector<tree_node> tree;
    vector<tree_node> lazy;
    vector<int> flag;

    segment_tree(int n, vector<int> v, int type){ //0-rmq, 1-rsq
        nearest(n);
        vals = vector<int>(v);
        for (int i=0;i<(N<<1);i++){
            tree.push_back(tree_node(0,0,0,0));
            lazy.push_back(tree_node(0,0,0,0));
        }
        flag = vector<int>(N<<1,0);
        if (type){
            build_rsq(1,1,N,n);
        }
        else {
            //build_rmq(1,1,N,n);
        }
    }

    segment_tree(int n, int value, int type){ //0-rmq, 1-rsq
        nearest(n);
        vals = vector<int>(n,value);
        for (int i=0;i<(N<<1);i++){
            tree.push_back(tree_node(0,0,0,0));
            lazy.push_back(tree_node(0,0,0,0));
        }
        flag = vector<int>(N<<1,0);
        if (type){
            build_rsq(1,1,N,n);
        }
        else {
            //build_rmq(1,1,N,n);
        }
    }

    void nearest(int n){
        N = 1;
        while(N<n){
            N<<=1;
        }
    }

    void add_value(int node, int ln, int rn){
        tree[node].sum = tree[ln].sum + tree[rn].sum;
        tree[node].pre = max(tree[ln].pre, tree[ln].sum+tree[rn].pre);
        tree[node].suf = max(tree[rn].suf, tree[rn].sum+tree[ln].suf);
        tree[node].ans = max(max(tree[ln].ans,tree[rn].ans), tree[ln].suf+tree[rn].pre);
    }

    void build_rsq(int node, int s, int e, int n){
        if (s>e){
            return;
        }
        if (s==e){ //leaf node
            if (s>n){
                tree[node] = tree_node(0,-1*inf,-1*inf,-1*inf);
            }
            else {
                tree[node] = tree_node(vals[s-1],vals[s-1],vals[s-1],vals[s-1]);
            }
            return;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        build_rsq(ln, s, mid, n);
        build_rsq(rn, mid+1, e, n);
        add_value(node,ln,rn);
    }

    int get_index(int index){ // 1-based index
        return tree[N+index-1].ans;
    }

    tree_node get_node(tree_node ln, tree_node rn){
        tree_node res(0,0,0,0);
        res.sum = ln.sum + rn.sum;
        res.pre = max(ln.pre, ln.sum+rn.pre);
        res.suf = max(rn.suf, rn.sum+ln.suf);
        res.ans = max(max(ln.ans,rn.ans), ln.suf+rn.pre);
        return res;
    }

    int rmq(int s, int e){
        return rmq_query(1,1,N,s,e).ans;
    }

    tree_node rmq_query(int node, int s, int e, int i, int j){
        //prepare(node,s,e);
        //printf("%d %d %d %d %d\n",node,s,e,i,j);
        if (s>e||s>j||e<i){
            return tree_node(0,-1*inf,-1*inf,-1*inf);
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        if (s>=i&&e<=j){
            return tree[node];
        }
        tree_node ls = rmq_query(ln,s,mid,i,j), rs = rmq_query(rn,mid+1,e,i,j);
        return get_node(ls,rs);
    }

    int rsq(int s, int e){
        return rsq_query(1,1,N,s,e);
    }

    int rsq_query(int node, int s, int e, int i, int j){
        //prepare(node,s,e);
        if (s>e||s>j||e<i){
            return 0;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        if (s>=i&&e<=j){
            return tree[node].sum;
        }
        return rsq_query(ln,s,mid,i,j)+rsq_query(rn,mid+1,e,i,j);
    }
/*
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
            lazy[node] = value;
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
                lazy[ln] = lazy[node];
                flag[ln] = 1;
                lazy[rn] = lazy[node];
                flag[rn] = 1;
            }
            flag[node] = 0;
        }
    }
*/
};



int main(){
    int n, x, y, q;
    scanf("%d", &n);
    vector<int> v;
    for (int i=0;i<n;i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    segment_tree st(n,v,1);
    scanf("%d", &q);
    for (int i=0;i<q;i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", st.rmq(x,y));
    }
}

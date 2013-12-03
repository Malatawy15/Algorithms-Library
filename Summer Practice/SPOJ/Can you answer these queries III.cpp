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
    static const int inf = 1000000000;
    int N;
    vector<int> vals;
    vector<tree_node> tree;

    segment_tree(int n, vector<int> v, int type){ //0-rmq, 1-rsq
        nearest(n);
        vals = vector<int>(v);
        for (int i=0;i<(N<<1);i++){
            tree.push_back(tree_node(0,0,0,0));
        }
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
        }
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

    tree_node get_node(tree_node ln, tree_node rn){
        tree_node res(0,0,0,0);
        res.sum = ln.sum + rn.sum;
        res.pre = max(ln.pre, ln.sum+rn.pre);
        res.suf = max(rn.suf, rn.sum+ln.suf);
        res.ans = max(max(ln.ans,rn.ans), ln.suf+rn.pre);
        return res;
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
        tree[node] = get_node(tree[ln],tree[rn]);
    }

    int rmq(int s, int e){
        return rmq_query(1,1,N,s,e).ans;
    }

    tree_node rmq_query(int node, int s, int e, int i, int j){
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

    void update(int ind, int value){
        return update_range(1,1,N,ind,value);
    }

    void update_range(int node, int s, int e, int ind,int value){
        //printf("UPDATE: %d %d %d %d\n",node,s,e,ind);
        if (s>e||s>ind||e<ind){
            return;
        }
        if (s==e){
            tree[node] = tree_node(value,value,value,value);
            return;
        }
        int mid = s+((e-s)>>1), ln = node<<1, rn = (node<<1)+1;
        if (ind>mid)
            update_range(rn,mid+1,e,ind,value);
        else update_range(ln,s,mid,ind,value);
        tree[node] = get_node(tree[ln],tree[rn]);
    }
};

int main(){
    int n, x, y, z, q;
    scanf("%d", &n);
    vector<int> v;
    for (int i=0;i<n;i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    segment_tree st(n,v,1);
    scanf("%d", &q);
    for (int i=0;i<q;i++){
        scanf("%d %d %d", &x, &y, &z);
        if (x)
            printf("%d\n", st.rmq(y,z));
        else st.update(y,z);
    }
}

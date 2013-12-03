#include<stdio.h>
#include<vector>
#include<algorithm>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <math.h>

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
                tree[node] = tree_node(vals[s-1]-1,vals[s-1]-1,vals[s-1]-1,vals[s-1]-1);
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

};

#define MAXSIEVE 1000005
#define MAXSIEVEHALF 500001
#define MAXSQRT 708

short a[500001];
int primes[500000];

int sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
    return k;
}

int isprime(int n){
    if(n==2) return 1;
    if((n&1)==0) return 0;
    if(a[n>>1]==0) return 1;
    return 0;
}

int p[1000005];

int main(){
    int i,j,k, n,L,R, cprime=sieve();

    p[1]=0;
    for(i=2; i<1000003; i++){
        if(isprime(i)){ p[i]=-1; continue; }

        j=0;
        n=i;
        p[i]=0;
        while(n>1 && primes[j]*primes[j]<=n){
            k=p[i];
            while(n%primes[j]==0) p[i]++, n/=primes[j];
            j++;
        }
        if(n>1) p[i]++;
    }
    int cn = 1;
    vector<int> vals;
    for (int i=1;i<=1000000;i++){
        vals.push_back(p[i]);
    }
    //printf("SiZE: %d\n", vals.size());
    segment_tree st(1000000,vals,1);
    while(scanf("%d %d", &L, &R)>0){
        if(R==-1||L==-1) return 0;
        printf("%d. %d\n",cn++,st.rmq(L,R));
    }
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int tree[500000];
int tree1[500000];
int vals[100010];
int maxN, N, Q, ON;

int build_tree(int node, int L, int R){
    if (L>ON)
        return -1;
    if (L>R)
        return -1;
    if (L==R){
        tree1[node] = vals[L];
        return tree[node] = vals[L];
    }

    else {
        int nl = (node<<1), nr = (node<<1)+1, l, r;
        l = build_tree(nl, L, (L+R)>>1);
        r = build_tree(nr, ((L+R)>>1)+1, R);
        tree1[node] = min(tree1[nl],tree1[nr]);
        return tree[node] = max(l, r);
    }
}

void update_node(int node, int L, int R, int target, int nv){
    int pos = target + N - 1;
    tree[pos] = nv;
    tree1[pos] = nv;
    pos>>=1;
    while(pos>1&&tree[pos]<nv){
        tree[pos] = nv;
        pos>>=1;
    }
    pos = target + N - 1;
    pos>>=1;
    while(pos>1&&tree1[pos]>nv){
        tree1[pos] = nv;
        pos>>=1;
    }
}

int RMQ(int node, int L, int R, int tl, int tr, int X){
    if (L>R)
        return 0;
    if (L>ON)
        return 0;
    if (R<tl||L>tr)
        return 0;
    if (L>=tl&&R<=tr&&tree[node]<=X){
        return R-L+1;
    }
    if (tree1[node]>X){
        return 0;
    }
    if (L==R)
        return 0;
    else {
        int mid = (L+R)>>1, nl = node<<1, nr = (node<<1)+1;
        return RMQ(nl, L, mid, tl, tr, X) + RMQ(nr, mid+1, R, tl, tr, X);
    }
}

int main(){
    int a, b, d;
    char c;
    scanf("%d %d", &N, &Q);
    maxN = 1;
    while(maxN<N)
        maxN<<=1;
    for (int i=1;i<=N;i++){
        scanf("%d", &vals[i]);
    }
    ON = N;
    N = maxN;
    memset(tree, -1, sizeof tree);
    for (int i=0;i<500000;i++){
        tree1[i] = 2000000000;
    }
    char inp[1];
    build_tree(1, 1, N);
    for (int i=0;i<Q;i++){
        scanf("%s %d %d", inp, &a,&b);
        if (inp[0]=='C'){
            scanf("%d",&d);
            printf("%d\n", RMQ(1, 1, N, a, b, d));
        }
        else {
            //scanf("%d %d",&a,&b);
            update_node(1, 1, N, a, b);
        }
    }
}

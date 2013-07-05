#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int tree[500000];
int vals[100010];
int maxN, N, Q, num, ON;

int build_tree(int node, int L, int R){
    //printf("%d\n", num++);
    if (L>ON)
        return -1;
    if (L>R)
        return -1;
    if (L==R)
        return tree[node] = vals[L];
    else {
        int nl = (node<<1), nr = (node<<1)+1, l, r;
        l = build_tree(nl, L, (L+R)>>1);
        r = build_tree(nr, ((L+R)>>1)+1, R);
        return tree[node] = max(l, r);
    }
}

void update_node(int node, int L, int R, int target, int nv){
    /*if (L>R)
        return;
    if (L==R)
        tree[node] = nv;
    else {
        int mid = (L+R)>>1, nl = node<<1, nr = (node<<1)+1;
        if (target<=mid)
            update_node(node<<1, L, mid, target, nv);
        else
            update_node((node<<1)+1, mid+1, R, target, nv);
        tree[node] = max(tree[nl], tree[nr]);
    }*/
    int pos = target + N - 1;
    tree[pos] = nv;
    pos>>=1;
    while(pos>1&&tree[pos]<nv){
        tree[pos] = nv;
        pos>>=1;
    }
}

int RMQ(int node, int L, int R, int tl, int tr, int X){
    if (L>R)
        return 0;
    if (R<tl||L>tr)
        return 0;
    if (L>=tl&&R<=tr&&tree[node]<=X)
        return R-L+1;
    if (L==R)
        return 0;
    else {
        int mid = (L+R)>>1, nl = node<<1, nr = (node<<1)+1;
        return RMQ(nl, L, mid, tl, tr, X) + RMQ(nr, mid+1, R, tl, tr, X);
    }
}

int main(){
    num = 0;
    int a, b, d;
    char c;
    char buf [10000];
    gets(buf);
    sscanf(buf, "%d %d", &N, &Q);
    maxN = 1;
    while(maxN<N)
        maxN<<=1;
    //printf("N & Q: %d %d\n", N, Q);
    for (int i=1;i<=N;i++){
      //  gets(buf);
    //    sscanf(buf, "%d", &vals[i]);
    vals[i] = i;
      //  printf("Val[%d] = %d\n", i, vals[i]);
    }
    printf("VALS %d\n", maxN);
    ON = N;
    N = maxN;
    memset(tree, -1, sizeof tree);
    build_tree(1, 1, N);
    printf("BUILD\n");
    //for (int i=1;i<10;i++)
      //  printf("Node #%d = %d\n", i, tree[i]);
    for (int i=0;i<Q;i++){
        gets(buf);
        char * pch;
        pch = strtok (buf," ");
        sscanf(pch, "%c", &c);
        pch = strtok (NULL, " ");
        if (c=='C'){
            sscanf(pch, "%d", &a);
            pch = strtok (NULL, " ");
            sscanf(pch, "%d", &b);
            pch = strtok (NULL, " ");
            sscanf(pch, "%d", &d);
        //    printf("C: %d %d %d\n", a, b, d);
            printf("%d\n", RMQ(1, 1, N, a, b, d));
        }
        else {
            sscanf(pch, "%d", &a);
            pch = strtok (NULL, " ");
            sscanf(pch, "%d", &b);
          //  printf("M: %d %d\n", a, b);
            update_node(1, 1, N, a, b);
        }
    }
}


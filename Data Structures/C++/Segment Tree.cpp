#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAXN 1000000
#define INF 1000000000

int sTree[(MAXN<<1)+10];
int vals[MAXN+10];
int N;

void init(int n){
    N = 1;
    while(N<n)
        N<<=1;
    for (int i=0;i<=N<<1;i++){
        sTree[i] = INF;
    }
    for (int i=1;i<=N;i++)
        if (i>n)
            vals[i] = INF;
        else scanf("%d", &vals[i]);
}

void build(int node, int b, int e){
    if (b==e)
        sTree[node] = vals[b];
    else{
        build(node<<1, b, (b+e)>>1);
        build((node<<1)+1, ((b+e)>>1)+1, e);
        sTree[node] = min(sTree[node<<1], sTree[(node<<1)+1]);
    }
}

void update(int ind, int nv){
    ind += N-1;
    sTree[ind] = nv;
    while(ind>1){
        ind>>=1;
        sTree[ind] = min(sTree[ind<<1], sTree[(ind<<1)+1]);
    }
}

int query(int node, int b, int e, int rb, int re){
    if (re<b||rb>e)
        return INF;
    if (b>=rb&&e<=re)
        return sTree[node];
    return min(query(node<<1, b, (b+e)>>1, rb, re), query((node<<1)+1, ((b+e)>>1)+1, e, rb, re));
}

int query(int rb, int re){
    return query(1, 1, N, rb, re);
}

int main(){
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
}

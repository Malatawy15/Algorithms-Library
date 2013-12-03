#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAXN 1000000
#define INF 1000000000

long long sTree[(MAXN<<1)+10];
long long add[(MAXN<<1)+10];
int N;

void init(int n){
    N = 1;
    while(N<n)
        N<<=1;
    memset(sTree,0,sizeof sTree);
    memset(add,0,sizeof add);
}

void prepare(int node, int b, int e, int mid){
    long long inter = 0LL;
    if (add[node]!=0){
        add[node<<1] += add[node];
        add[(node<<1)+1] += add[node];
        inter = (mid-b+1);
        inter*=add[node];
        sTree[node<<1] += inter;
        inter = (e-mid);
        inter*=add[node];
        sTree[(node<<1)+1] += inter;
    }
    add[node] = 0LL;
}

void update(int node, int b, int e, int i, int j, long long nv){
    if (b>j||e<i)
        return;
    if (b>=i&&e<=j){
        sTree[node]+=((e-b+1)*nv);
        add[node]+=nv;
    }
    else{
        prepare(node, b, e, (b+e)>>1);
        update(node<<1, b, (b+e)>>1,i,j,nv);
        update((node<<1)+1, ((b+e)>>1)+1, e,i,j,nv);
        sTree[node] = sTree[node<<1] + sTree[(node<<1)+1];
    }
    //printf("%d %d %d %lld\n", node,b,e,sTree[node]);
}

void update(int si, int ei, long long nv){
    update(1,1,N,si,ei,nv);
}

long long query(int node, int b, int e, int rb, int re){
    if (re<b||rb>e)
        return 0LL;
    if (b>=rb&&e<=re)
        return sTree[node];
    prepare(node, b, e, (b+e)>>1);
    return query(node<<1, b, (b+e)>>1, rb, re)+query((node<<1)+1, ((b+e)>>1)+1, e, rb, re);
}

int query(int rb, int re){
    return query(1, 1, N, rb, re);
}

int main(){
    int t,n,p,q,r;
    long long v, res = 0LL;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &r);
        init(n);
        while(r--){
            scanf("%d",&n);
            if (n){
                scanf("%d %d", &p, &q);

                res = query(p,q);
                printf("%lld\n",res);
            }
            else{
                scanf("%d %d %lld", &p, &q, &v);
                //printf("Update: %lld\n",v);

                update(p,q,v);
            }
        }
    }
}

#include<stdio.h>
#include<string.h>

using namespace std;

int N, C;
long long ft[100001];
long long vals[100001];

void update(int pos, int v){
    int n = pos;
    while(n<=N){
        ft[n]+=v;
        n+=(n&(-n));
    }
}

void add(int p, int q, int v){
    long long rn = 0LL,s = 0LL;
    for (int i=p;i<=q;i++){
        vals[i]+=v;
        update(i,v);
    }
}

long long rsq(int p, int q){
    long long s1 = 0LL, s2 = 0LL;
    int n1 = p, n2 = q;
    while(n1>0){
        s1+=ft[n1];
        n1-= (n1&(-n1));
    }
    while(n2>0){
        s2+=ft[n2];
        n2-= (n2&(-n2));
    }
    return s2-s1+vals[p];
}

int main(){
    int t,x,y,z;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &C);
        memset(ft, 0, sizeof ft);
        memset(vals, 0, sizeof vals);
        for (int i=0;i<C;i++){
            scanf("%d", &x);
            if (!x){
                scanf("%d %d %d", &x, &y, &z);
                add(x,y,z);
            }
            else{
                scanf("%d %d", &x, &y);
                printf("%lld\n", rsq(x,y));
            }
        }
    }
}


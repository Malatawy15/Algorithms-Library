#include<stdio.h>
#include<string.h>

using namespace std;

long long pows [60];
long long sums [60];

int main(){
    pows[0] = 1LL;
    sums[0] = 0LL;
    for (int i=1;i<60;i++){
        sums[i] = sums[i-1]+pows[i-1];
        //printf("%d %lld\n", i, sums[i]);
        pows[i] = pows[i-1]<<1;
    }
    int ind;
    long long G,T,A,D,nt = 0LL, ng = 0LL, tba=0LL;
    scanf("%lld %lld %lld %lld", &G, &T, &A, &D);
    while(!(G==-1&&T==-1&&A==-1&&D==-1)){
        nt = 0LL, ng = 0LL, tba=0LL;
        nt = G*A+D;
        for (int i=0;i<60;i++)
        if (pows[i]>=nt){
            ind = i;
            tba = pows[i] - nt;
            nt = pows[i];
            break;
        }
        ng = T*(T-1);
        ng >>=1;
        ng*=G;
        ng+=sums[ind];
        //ng = (G*((T*(T-1))/2))+sums[nt];
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n", G,A,T,D,ng,tba);
        scanf("%lld %lld %lld %lld", &G, &T, &A, &D);
    }
}

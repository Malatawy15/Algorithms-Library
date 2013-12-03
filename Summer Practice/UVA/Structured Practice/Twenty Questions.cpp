#include<stdio.h>
#include<string.h>
#include<bitset>
#include<algorithm>

using namespace std;

int N, M;

char q[130][15];
bitset<128> bs[130][15];


void precompute(){
    for (int i=0;i<N;i++){
        bitset<128> b1, b2;
        b1.reset();
        b2.reset();
        for (int j=0;j<M;j++){
            if (q[j][i]=='0')
                b1[j] = 1;
            else b2[j] = 1;
        }
        for (int j=0;j<M;j++){
            bs[j][i].reset();
            if (q[j][i]=='0')
                bs[j][i] = b1;
            else bs[j][i] = b2;
        }
    }
}

int pow_2(){
    int ans = 1;
    for (int i=0;i<N;i++)
        ans<<=1;
    return ans;
}
bitset<128> init;
int can(int bit, int sq){
    for (int j=0;j<M;j++){
        bitset<128> b;
        b.reset();
        b|=init;
        for (int k=0;k<N;k++){
            if (bit&(1<<k)){
                b&=bs[j][k];
            }
        }
        b[j] = 0;
        if (b.any()){
            return 0;
        }
    }
    return 1;
}

int main(){
    scanf("%d %d", &N, &M);
    while(!(!N&&!M)){
        for (int i=0;i<M;i++)
            scanf("%s", q[i]);
        precompute();
        int tt = pow_2();
        //printf("POW: %d\n",tt);
        int mini = N;
        init.reset();
        for (int k=0;k<M;k++)
            init[k] = 1;
        for (int i=0;i<tt;i++){
            int sq = 0;
            for (int k=0;k<N;k++){
                if (i&(1<<k)){
                    sq++;
                }
            }
            if (can(i, sq)){
                mini = min(mini,sq);
            }
        }
        printf("%d\n", mini);
        scanf("%d %d", &N, &M);
    }
}

#include<stdio.h>
#include<string.h>
#include<bitset>
#include<algorithm>

using namespace std;

int N, M;
const int INF = 1000;

char q[130][20];
bitset<130> ques[20];

int dp[20][2100];

bitset<130> init;

void set_up(){
    for (int i=0;i<M;i++)
        scanf("%s", q[i]);
    for (int i=0;i<N;i++){
        ques[i].reset();
        for (int j=0;j<M;j++){
            ques[i][j] = (q[j][i]=='1');
        }
    }
    init.reset();
    for (int i=0;i<M;i++)
        init[i] = 1;
}

int check(int bit){
    for (int i=0;i<M;i++){
        bitset<130> b (init);
        for (int j=0;j<N;j++){
            if ((bit&(1<<j))!=0){
                if (ques[j][i])
                    b&=ques[j];
                else{
                    ques[j].flip();
                    b&=ques[j];
                    ques[j].flip();
                }
            }
        }
        b[i] = 0;
        if (b.any()) return 0;
    }
    return 1;
}

int minimize(int n, int bit){
    if (n==N){
        if (check(bit)) return 0; else return INF;
    }
    if (dp[n][bit]!=-1)
        return dp[n][bit];
    return dp[n][bit] = min(minimize(n+1,bit),1+minimize(n+1,bit|(1<<n)));
}

int main(){
    scanf("%d %d", &N, &M);
    while(!(!N&&!M)){
        set_up();
        memset(dp,-1,sizeof dp);
        printf("%d\n", minimize(0,0));
        scanf("%d %d", &N, &M);
    }
}

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define INF 1000000000

int cost [152][152][152];
int N, P, Q;
int cities[152];

void initialize(){
    for (int i=0;i<=N;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<N;k++)
                cost[i][j][k] = INF;
}

void floyd_warshall(){
    for (int k=1;k<=P;k++)
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                cost[k][i][j] = min(cost[k-1][i][j], cost[k-1][i][cities[k]]+cost[k-1][cities[k]][j]);
}

int main(){
    int t, c, s, d, k;
    scanf("%d", &t);
    for (int cases=1;cases<=t;cases++){
        scanf("%d", &N);
        initialize();
        for (int i=0;i<N-1;i++){
            for (int j=i+1;j<N;j++){
                scanf("%d", &c);
                if (c!=-1){
                    cost[0][i][j] = c;
                    cost[0][j][i] = c;
                }

            }
        }
        scanf("%d", &P);
        for (int i=1;i<=P;i++){
            scanf("%d", &c);
            cities[i] = c-1;
        }
        floyd_warshall();
        scanf("%d", &Q);
        printf("Case %d: ", cases);
        for (int i=0;i<Q-1;i++){
            scanf("%d %d %d", &k, &s, &d);
        if (s==d)
            printf("0 ");
        else if (cost[k][s-1][d-1]!=INF)
            printf("%d ", cost[k][s-1][d-1]);
        else printf("-1 ");
        }
        scanf("%d %d %d", &k, &s, &d);
        if (s==d)
            printf("0\n");
        else if (cost[k][s-1][d-1]!=INF)
            printf("%d\n", cost[k][s-1][d-1]);
        else printf("-1\n");
    }
}

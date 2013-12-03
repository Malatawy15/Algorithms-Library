#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int inf = 100000000;

int S1, S2;
int c1 [200][200];
int c2 [200][200];
char g1 [200][200];
char g2 [200][200];
int dp[500][500];

int check(){
    for (int i=0;i<S1;i++){
        for (int j=0;j<S1;j++){
            if ((g1[i][j]=='0'&&dp[i][j]!=0)||(g1[i][j]=='1'&&dp[i][j]!=1))
                return 1;
        }
    }
    for (int i=0;i<S2;i++){
        for (int j=0;j<S2;j++){
            if ((g2[i][j]=='0'&&dp[i+S1][j+S1]!=0)||(g2[i][j]=='1'&&dp[i+S1][j+S1]!=1))
                return 1;
        }
    }
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &S1);
        for (int i=0;i<S1;i++)
            scanf("%s", g1[i]);
        for (int i=0;i<S1;i++){
            for (int j=0;j<S1;j++){
                switch(g1[i][j]){
                    case '0': c1[i][j] = 0;break;
                    case '1': c1[i][j] = 1;break;
                    case 'x': c1[i][j] = 1;break;
                }
            }
        }
        scanf("%d", &S2);
        for (int i=0;i<S2;i++)
            scanf("%s", g2[i]);
        for (int i=0;i<S2;i++){
            for (int j=0;j<S2;j++){
                switch(g2[i][j]){
                    case '0': c2[i][j] = 0;break;
                    case '1': c2[i][j] = 1;break;
                    case 'x': c2[i][j] = 1;break;
                }
            }
        }
        for (int i=0;i<S1;i++)
            for (int j=0;j<S1;j++)
                for (int k=0;k<S1;k++)
                    c1[i][j] = min(c1[i][j], c1[i][k]+c1[k][j]);
        for (int i=0;i<S2;i++)
            for (int j=0;j<S2;j++)
                for (int k=0;k<S2;k++)
                    c2[i][j] = min(c2[i][j], c2[i][k]+c2[k][j]);
        int ns = S1+S2;
        for (int i=0;i<ns;i++)
            for (int j=0;j<ns;j++)
                dp[i][j] = 1;
        for (int i=0;i<S1;i++){
            for (int j=0;j<S1;j++){
                dp[i][j] = c1[i][j];
            }
        }
        for (int i=0;i<S2;i++){
            for (int j=0;j<S2;j++){
                dp[i+S1][j+S1] = c2[i][j];
            }
        }
        for (int i=0;i<ns;i++)
            for (int j=0;j<ns;j++)
                for (int k=0;k<ns;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        if (check()){
            printf("NO\n");
        }
        else {
            printf("YES\n");
            for (int i=0;i<ns;i++){
                for (int j=0;j<ns;j++)
                    printf("%d",dp[i][j]);
                printf("\n");
            }
        }
    }
}

/*
2
3
011
10x
1x0
2
01
10
2
0x
x0
4
010x
1010
0100
x000
*/

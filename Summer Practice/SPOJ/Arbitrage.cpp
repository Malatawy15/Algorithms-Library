#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<map>

using namespace std;

#define Change pair<int, double>
#define EPS 1e-9

double dp[35][35];
int N,M;
map<string,int> m_c;

int main(){
    char name[200];
    char n1[200];
    char n2[200];
    double val;
    int c1,c2,c=1;
    scanf("%d",&N);
    while(N){
        for (int i=0;i<N;i++){
            scanf("%s", name);
            m_c.insert(make_pair(name,i));
        }
        scanf("%d",&M);
        memset(dp,0,sizeof dp);
        for (int i=0;i<M;i++){
            scanf("%s %lf %s",n1,&val,n2);
            c1 = m_c[n1];
            c2 = m_c[n2];
            dp[c1][c2] = val;
        }
        for (int k=0;k<N;k++)
            for (int i=0;i<N;i++)
                for (int j=0;j<N;j++)
                    if (dp[i][j]<dp[i][k]*dp[k][j])
                        dp[i][j]=dp[i][k]*dp[k][j];
        int found = 0;
        for (int i=0;i<N;i++)
            if (dp[i][i]>1.0)
                found = 1;
        if (found)
            printf("Case %d: Yes\n",c++);
        else printf("Case %d: No\n",c++);
        m_c.clear();
        scanf("%d",&N);
    }
}

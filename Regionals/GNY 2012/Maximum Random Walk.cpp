#include<stdio.h>
#include<string.h>

using namespace std;

double dp[2010][1100][2];
int vis[2020][1100][2];
int c, cn, L;
double pL, pR, pS;

double calc(int pos, int len, int togo, int reached){
    if (pos>togo)
        return 0;
    if (pos==togo){
        reached = 1;
    }
    if (len==0){
        return (reached)*(togo-1010);
    }
    if (vis[pos][len][reached]==cn)
        return dp[pos][len][reached];
    vis[pos][len][reached] = cn;
    return dp[pos][len][reached] = pL*calc(pos-1,len-1,togo,reached)+pR*calc(pos+1,len-1,togo,reached)+pS*calc(pos,len-1,togo,reached);
}

int main(){
    int t;
    scanf("%d", &t);
    cn = 1;
    while(t--){
        scanf("%d %d %lf %lf",&c,&L, &pL, &pR);
        pS = 1-pL-pR;
        double tot = 0.0;
        for (int i=1;i<=L;i++){
            tot+=(calc(1010,L,i+1010,0));
            cn++;
        }
        printf("%d %.4lf\n",c,tot);
    }
}

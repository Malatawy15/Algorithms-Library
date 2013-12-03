#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int N;
string dp[51][51];
int vis[51][51];

int is_palindrome(string s){
    int ss = s.size();
    for (int i=0;i<ss>>1;i++)
        if (s[i]!=s[ss-i-1])
            return 0;
    return 1;
}

string find_pali(int x, int y){
    if (x==y)
        return "";
    string maxi = dp[x][y];
    if (vis[x][y])
        return dp[x][y];
    vis[x][y] = 1;
    for (int i=x+1;i<y;i++)
        for (int j=i;j<y;j++)
            if (dp[x][i]==dp[j][y]){
                string ns = dp[x][i]+find_pali(i,j)+dp[j][y];
                //printf("%d %d %d %d %s %s\n",x,i,j,y,maxi.c_str(), ns.c_str());
                int s1 = maxi.size(), s2 = ns.size();
                if (s2>s1)
                    maxi = ns;
                else if (s2==s1)
                    maxi = min(maxi, ns);
            }
    //printf ("RET: %d %d %s\n",x,y,maxi.c_str());
    return dp[x][y] = maxi;
}

/*
string floyd_warshall(){
    for (int k=0;k<N;k++)
        for (int i=0;i<k;i++)
            for (int j=k+1;j<N;j++){
                if (dp[i][k][0]!='*'&&dp[k][j][0]!='*'){
                    string ns = dp[i][k]+dp[k][j];
                    if (!is_palindrome(ns))
                        continue;
                    printf ("STEP: %s %s %d %d %d\n",dp[i][j].c_str(),ns.c_str(),i,k,j);
                    int s1 = ns.size(), s2 = dp[i][j].size();
                    if (s1>s2)
                        dp[i][j] = ns;
                    else if (s1==s2)
                        dp[i][j] = min(ns,dp[i][j]);
                }
            }
    return dp[0][N-1];
}
*/
int main(){
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    char buf [60];
    scanf("%d", &t);
    while(t--){
        memset(vis,0,sizeof vis);
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%s", buf);
            for (int j=0;j<N;j++)
                if (j==i)
                    dp[i][j]="";
                else dp[i][j] = buf[j];
        }
        printf("%s\n", find_pali(0,N-1).c_str());
    }
}

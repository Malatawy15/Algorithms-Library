#include <stdio.h>
#include <string.h>

using namespace std;

char grid[101][101];

int vis[101][101][26];

int main(){
    memset(vis,0,sizeof vis);
    int M, N, K, sum = 0, ns, ss;
    scanf("%d %d %d", &M, &N, &K);
    for (int i=1;i<=M;i++){
        scanf("%s", grid[i]);
        /*for (int j=1;j<=N;j++){
            vis[i][j][grid[i][j-1]-'A']++;
            for (int k=0;k<26;k++){
                vis[i][j][k]+=vis[i-1][j][k];
                vis[i][j][k]+=vis[i][j-1][k];
                vis[i][j][k]-=vis[i-1][j-1][k];
            }
        }*/
    }
    for (int i=1;i<=M;i++)for (int j=1;j<=N;j++)
    for (int x = i;x<=M;x++)for (int y=j;y<=N;y++){
        ss = 0;
        for (int k=0;k<26;k++){
            ns = vis[x][y][k];
            ns-=vis[i-1][y][k];
            ns-=vis[x][j-1][k];
            ns+=vis[i-1][j-1][k];
            if (ns>0)
                ss++;
        }
        if (ss==K)
            sum++;
    }
    printf("%d\n", sum);
}

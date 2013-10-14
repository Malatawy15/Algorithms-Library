#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};

int vis[11][11];
int N;

int dfs(int x, int y){
    if (vis[x][y])
        return 0;
    vis[x][y] = 1;
    int sum = -1;
    for (int i=0;i<8;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<N&&ny<10){
            sum= max(sum, dfs(nx, ny));
        }
    }
    vis[x][y] = 0;
    return sum+1;
}

int main(){
    int offset, num, sx, sy, cases = 1, tot;
    scanf("%d", &N);
    while(N){
        tot = 0;
        memset(vis, 0, sizeof vis);
        sy = 0;
        for (int i=0;i<N;i++){
            scanf("%d %d", &offset, &num);
            for (int j=0;j<offset;j++)
                vis[i][j] = 1;
            for (int j = num+offset;j<10;j++)
                vis[i][j] = 1;
            tot+=num;
            if (!i)
                sx = offset;
        }
        int x = tot-dfs(sx, sy);
        if (x==1)
            printf("Case %d, %d square can not be reached.\n", cases++, 1);
        else printf("Case %d, %d squares can not be reached.\n", cases++, x);
        scanf("%d", &N);
    }
}

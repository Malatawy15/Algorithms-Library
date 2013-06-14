#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

char map[60][60];
int vis[60][60];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int h, w;

int dfs(int x, int y, int offset){
    if (x<0||y<0||x>=h||y>=w||vis[x][y]||map[x][y]-'A'!=offset)
        return -1;
    int maximum = 0, num;
    vis[x][y] = 1;
    for (int i =0;i<8;i++){
        num = dfs(x+dx[i], y+dy[i], offset+1);
        maximum = max(maximum, num);
    }
    return maximum+1;
}

int main(){
    scanf("%d %d", &h, &w);
    int maximum = 0, num, c = 1;
    while (!(h==0&&w==0)){
        maximum = 0;
        for (int i =0;i<h;i++)
            scanf("%s", map[i]);
        for (int i =0;i<h;i++)
            for (int j=0;j<w;j++)
                if (map[i][j]=='A'){
                    memset(vis, 0, sizeof vis);
                    num = dfs(i, j, 0);
                    maximum = max(maximum, num);
                }
        printf("Case %d: %d\n", c++, maximum);
        scanf("%d %d", &h, &w);
    }
}

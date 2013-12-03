#include <stdio.h>
#include <string.h>

using namespace std;

int M, N, cnt, sx, sy, ex, ey;

char grid[21][21];
int vis[21][21];

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int check(){
	for (int i=0;i<M;i++)
		for (int j =0;j<N;j++)
			if ((i==0||i==M-1||j==0||j==N-1)&&grid[i][j]=='.'){
	            if (cnt==0){
	                sx = i;
	                sy = j;
	            }
	            else if (cnt==1){
	                ex = i;
	                ey = j;
	            }
	            else return 0;
	            cnt++;
	        }
    if (cnt==2)
        return 1;
    else return 0;
}

int dfs(int x, int y){
    if (x==ex&&y==ey)
        return 1;
    if (vis[x][y])
        return 0;
    vis[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<M&&ny<N&&grid[nx][ny]!='#')
            if (dfs(nx,ny))
                return 1;

    }
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &M, &N);
        for (int i=0;i<M;i++)
            scanf("%s", grid[i]);
        if (M==1&&N==1){
        	printf("invalid\n");
        	continue;
        }
        memset(vis,0,sizeof vis);
        cnt = 0;
        if (check()&&dfs(sx, sy))
            printf("valid\n");
        else printf("invalid\n");
    }
}

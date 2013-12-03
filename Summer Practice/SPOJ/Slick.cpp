#include <stdio.h>
#include <string.h>

using namespace std;

int N, M;
int grid[251][251];
int vis[251][251];
int counts[62502];

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int dfs(int x, int y){
    if (vis[x][y]||grid[x][y]==0)
        return 0;
    vis[x][y] = 1;
    int cnt = 1;
    for (int i=0;i<4;++i){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<N&&ny<M&&!vis[nx][ny]&&grid[x][y]==1)
            cnt+=dfs(nx,ny);
    }
    return cnt;
}

void counter(){
    int num = 0;
    memset(vis, 0, sizeof vis);
    memset(counts, 0, sizeof counts);
    for (int i=0;i<N;i++)
    	for (int j=0;j<M;j++)
        	if (grid[i][j]==1&&vis[i][j]==0)
            	num++, counts[dfs(i,j)]++;
    printf("%d\n", num);
    for (int i=0;i<=N*M;i++){
        if (counts[i]>0)
            printf("%d %d\n", i, counts[i]);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    while(!(!N&&!M)){
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                scanf("%d", &grid[i][j]);
        counter();
        scanf("%d %d", &N, &M);
    }
}

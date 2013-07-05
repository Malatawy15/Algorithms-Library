#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

char grid [1010][1010];
int vis [1001][1001];

int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,1,-1};

int R, C;

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

int bfs(int sx, int sy, int fx, int fy){
    memset(vis,-1,sizeof vis);
    queue<Point> q;
    q.push(mp(sx,sy,0));
    vis[sx][sy] = 0;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (p.X==fx&&p.Y==fy)
            return p.cost;
        if (p.cost>vis[p.X][p.Y]||grid[p.X][p.Y]=='X'||vis[p.X][p.Y]==-1)
            continue;
        //vis[p.X][p.Y] = p.cost;
        for (int i=0;i<8;i++){
            int j =1,nx,ny;
            while(1){
                nx = p.X+dx[i]*j;
                ny = p.Y+dy[i]*j;
                if (inside_grid(nx,ny)&&grid[nx][ny]!='X'){
                    if ((vis[nx][ny]==-1||vis[nx][ny]>p.cost+1)){
                        q.push(mp(nx, ny,p.cost+1));
                        vis[nx][ny] = p.cost+1;
                    }
                }
                else break;
                j++;
            }
        }
    }
    return -1;
}

int main(){
    int t,sx,sy,fx,fy;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&R,&C);
        for (int i=0;i<R;i++)
            scanf("%s",grid[i]);
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++)
                if (grid[i][j]=='S'){
                    sx = i;sy=j;
                }
                else if (grid[i][j]=='F'){
                    fx = i;fy=j;
                }
        printf("%d\n", bfs(sx,sy,fx,fy));
    }
}

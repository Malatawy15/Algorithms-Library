#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

bool vis[1000][1000];
int R,C,n,r,c,x;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

int bfs(int sx, int sy, int ex, int ey){
    queue<Point> q;
    q.push(mp(sx, sy, 0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (vis[p.X][p.Y])
            continue;
        vis[p.X][p.Y] = 1;
        if (p.X==ex&&p.Y==ey)
            return p.cost;
        for (int i=0;i<4;i++){
            int nx=p.X+dx[i], ny=p.Y+dy[i];
            if (inside_grid(nx, ny) ){
                q.push(mp(nx, ny, p.cost+1));
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d",&R,&C);
    while (!(R==0&C==0)){
        memset(vis, 0, sizeof vis);
        scanf("%d", &n);
        while(n--){
            scanf("%d", &r);
            scanf("%d", &x);
            while(x--){
                scanf("%d", &c);
                vis[r][c]=1;
            }
        }
        scanf("%d %d", &r, &c);
        scanf("%d %d", &x, &n);
        printf("%d\n",bfs(r, c, x, n));
        scanf("%d %d",&R,&C);
    }
}

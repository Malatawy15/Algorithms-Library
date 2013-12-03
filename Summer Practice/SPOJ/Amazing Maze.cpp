#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int N, M;
char grid[201][201];
int vis[201][201];
int times[201][201];
int nx, ny, cx, cy;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(){
    memset(vis, 0, sizeof vis);
    queue<Point> q;
    q.push(mp(nx,ny,0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (p.X==cx&&p.Y==cy)
            return p.cost;
        if (vis[p.X][p.Y])
            continue;
        if (grid[p.X][p.Y]=='#'&&times[p.X][p.Y]>p.cost){
            q.push(mp(p.X,p.Y,p.cost+1));
            continue;
        }
        vis[p.X][p.Y] = 1;
        for (int i=0;i<4;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (nx>=0&&nx<M&&ny>=0&&ny<N){
                q.push(mp(nx,ny,p.cost+1));
            }
        }
    }
    return -1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &M, &N);
        for (int i=0;i<M;i++)
            scanf("%s", grid[i]);
        for (int i=0;i<M;i++)
            for (int j=0;j<N;j++)
                scanf("%d", &times[i][j]);
        scanf("%d %d",&nx, &ny);
        scanf("%d %d",&cx, &cy);
        printf("%d\n", bfs());
    }
}

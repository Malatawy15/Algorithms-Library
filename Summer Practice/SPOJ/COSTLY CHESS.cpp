#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int sx, sy, fx, fy;

#define Pos pair<int, pair<int, int> >
#define cost first
#define X second.first
#define Y second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int dx[]={2,2,1,-1,1,-1,-2,-2};
int dy[]={-1,1,2,2,-2,-2,1,-1};

int vis[8][8];

int dij(){
    priority_queue<Pos, vector<Pos>, greater<Pos> > pq;
    memset(vis, 0, sizeof vis);
    pq.push(mp(0,sx,sy));
    while(!pq.empty()){
        Pos p = pq.top();
        pq.pop();
        if (vis[p.X][p.Y])
            continue;
        if (p.X==fx&&p.Y==fy)
            return p.cost;
        vis[p.X][p.Y] = 1;
        for (int i=0;i<8;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (nx>=0&&ny>=0&&nx<8&&ny<8&&!vis[nx][ny])
                pq.push(mp(p.cost+p.X*nx+p.Y*ny,nx,ny));
        }
    }
    return -1;
}

int main(){
    while(scanf("%d %d %d %d", &sx,&sy,&fx,&fy)>0){
        printf("%d\n", dij());
    }
}

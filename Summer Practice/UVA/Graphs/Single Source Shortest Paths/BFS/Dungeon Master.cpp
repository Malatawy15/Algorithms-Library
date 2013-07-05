#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Point pair<int, pair<int, pair<int,int> > >
#define X first
#define Y second.first
#define Z second.second.first
#define cost second.second.second
#define mp(a,b,c,d) make_pair(a, make_pair(b, make_pair(c, d)))

int dx[]={0,0,1,0,-1,0};
int dy[]={0,0,0,1,0,-1};
int dz[]={1,-1,0,0,0,0};

int vis[31][31][31];

int L,R,C;
int sx,sy,sz,ex,ey,ez;

int inside_grid(int x, int y, int z){
    return x>=0&&y>=0&&z>=0&&x<R&&y<C&&z<L;
}

int bfs(){
    queue<Point> q;
    q.push(mp(sx,sy,sz,0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (vis[p.X][p.Y][p.Z])
            continue;
        if (p.X==ex&&p.Y==ey&&p.Z==ez)
            return p.cost;
        vis[p.X][p.Y][p.Z] = 1;
        for (int i=0;i<6;i++){
            int nx=p.X+dx[i], ny=p.Y+dy[i], nz=p.Z+dz[i];
            if (inside_grid(nx,ny,nz))
                q.push(mp(nx,ny,nz,p.cost+1));
        }
    }
    return -1;
}

int main(){
    scanf("%d %d %d", &L, &R, &C);
    while(!(L==0&&R==0&&C==0)){
        memset(vis,0,sizeof vis);
        char buf[50];
        for (int i=0;i<L;i++){
            for (int j=0;j<R;j++){
                scanf("%s",buf);
                for (int k=0;k<C;k++){
                    if (buf[k]=='#')
                        vis[j][k][i] = 1;
                    else if (buf[k]=='S'){
                        sx = j;
                        sy = k;
                        sz = i;
                    }
                    else if (buf[k]=='E'){
                        ex = j;
                        ey = k;
                        ez = i;
                    }
                }
            }
        }
        int ans = bfs();
        if (ans==-1)
            printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ans);
        scanf("%d %d %d", &L, &R, &C);
    }
}

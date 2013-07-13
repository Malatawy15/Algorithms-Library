#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Point pair<int, pair<int, pair<int, int> > >
#define X first
#define Y second.first
#define state second.second.first
#define cost second.second.second
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))


int N, M;
char grid[101][101];
int vis[101][101][2];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<N&&y<M;
}

int bfs(int sx, int sy){
    memset(vis,0,sizeof vis);
    queue<Point> q;
    q.push(mp(sx,sy,0,0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (!inside_grid(p.X,p.Y))
            return p.cost;
        if (vis[p.X][p.Y][p.state])
            continue;
        if (grid[p.X][p.Y]=='W'||(!p.state&&grid[p.X][p.Y]=='D'))
            continue;
        vis[p.X][p.Y][p.state] = 1;
        int ns = p.state;
        if (grid[p.X][p.Y]=='O')
            ns = 1;
        else if (grid[p.X][p.Y]=='C')
            ns = 0;
        for (int i=0;i<4;i++){
            int nx=p.X+dx[i],ny=p.Y+dy[i];
            q.push(mp(nx,ny,ns,p.cost+1));
        }
    }
    return -1;
}

int main(){
    scanf("%d %d",&N,&M);
    while(!(N==-1&&M==-1)){
        for (int i=0;i<N;i++)
            scanf("%s",grid[i]);
        int sx, sy;
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                if (grid[i][j]=='H'){
                    sx = i;
                    sy = j;
                }
        printf("%d\n", bfs(sx,sy));
        scanf("%d %d",&N,&M);
    }
}

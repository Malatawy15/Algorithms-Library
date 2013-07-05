#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int vis[210][210];
int R,C,m,n;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int inside_grid(int x,int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

int bfs(){
    queue<Point> q;
    q.push(mp(0,0,0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (vis[p.X][p.Y])
            continue;
        if (p.X==R-1&&p.Y==C-1)
            return p.cost;
        vis[p.X][p.Y] = 1;
        for (int i=0;i<4;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (inside_grid(nx, ny))
                q.push(mp(nx,ny,p.cost+1));
        }
    }
    return -1;
}

int main(){
    int x,y,L;
    scanf("%d %d", &R, &C);
    while(!(R==0&&C==0)){
        //printf("NEW: %d %d\n",R,C);
        memset(vis, 0, sizeof vis);
        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&x,&y);
            vis[x-1][y-1] = 1;
        }
        scanf("%d",&n);
        while(n--){
            scanf("%d %d %d",&x,&y,&L);
            x--;y--;
            L*=L;
            for (int i=0;i<R;i++)
                for (int j=0;j<C;j++)
                    if ((x-i)*(x-i)+(y-j)*(y-j)<=L)
                        vis[i][j] = 1;
        }
        int ans = bfs();
        if (ans==-1)
            printf("Impossible.\n");
        else printf("%d\n",ans);
        scanf("%d %d", &R, &C);
    }
}

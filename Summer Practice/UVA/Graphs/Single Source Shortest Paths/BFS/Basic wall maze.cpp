#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<queue>
#include<set>

using namespace std;

#define Path pair<int, pair<int, string> >
#define X first
#define Y second.first
#define path second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

#define Pair pair<int, pair<int, pair<int, int> > >
#define mpl(a,b,c,d) make_pair(a, make_pair(b, make_pair(c, d)))

int vis[6][6];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char seq[]={'N','E','S','W'};
set<Pair> fp;

int inside_board(int x, int y){
    return x>=0&&y>=0&&x<6&&y<6;
}

string bfs(int x, int y, int desX, int desY){
    queue<Path> q;
    q.push(mp(x, y, ""));
    while (!q.empty()){
        Path p = q.front();
        q.pop();
        if (vis[p.X][p.Y])
            continue;
        if (p.X==desX&&p.Y==desY)
            return p.path;
        vis[p.X][p.Y] = 1;
        for (int i=0;i<4;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (inside_board(nx, ny)&&!vis[nx][ny]&&fp.count(mpl(p.X,p.Y,nx,ny))==0&&fp.count(mpl(nx,ny,p.X,p.Y))==0)
                q.push(mp(nx, ny, p.path+seq[i]));
        }
    }
    return "Not Found";
}

void draw_wall(int sx, int sy, int ex, int ey){
    if (sx==ex){
        for (int i=sy;i<ey;i++){
            fp.insert(mpl(i, sx-1, i,sx));
        }
    }
    else if (sy==ey){
        for (int i=sx;i<ex;i++){
            fp.insert(mpl(sy-1,i,sy,i));
        }
    }
}

int main(){
    int sx, sy, ex, ey, wsx, wex, wsy, wey;
    scanf("%d %d", &sy, &sx);
    while(!(!sx&&!sy)){
        memset(vis, 0, sizeof vis);
        fp.clear();
        scanf("%d %d", &ey, &ex);
        sx--;sy--;ex--;ey--;
        scanf("%d %d %d %d", &wsx, &wsy, &wex, &wey);
        draw_wall(wsx, wsy, wex, wey);
        scanf("%d %d %d %d", &wsx, &wsy, &wex, &wey);
        draw_wall(wsx, wsy, wex, wey);
        scanf("%d %d %d %d", &wsx, &wsy, &wex, &wey);
        draw_wall(wsx, wsy, wex, wey);
        printf("%s\n", bfs(sx, sy, ex, ey).c_str());
        scanf("%d %d", &sy, &sx);
    }
}

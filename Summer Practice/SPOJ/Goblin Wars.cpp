#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

#define Point pair<pair<int, int>, pair<char, pair<int, int> > >
#define X first.first
#define Y first.second
#define per second.first
#define time second.second.first
#define prev second.second.second
#define mp(a,b,c,d,e) make_pair(make_pair(a,b), make_pair(c,make_pair(d,e)))

int R, C;
char grid [501][501];
int vis [501][501];
char final_grid[501][501];
queue<Point> qq;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(){
    while(!qq.empty()){
        Point q = qq.front();
        qq.pop();
        if (grid[q.X][q.Y]=='#'||final_grid[q.X][q.Y]=='*')
            continue;
        if (q.prev!=-1){
            int nx = q.X-dx[q.prev], ny = q.Y-dy[q.prev];
            if (final_grid[nx][ny]=='*')
                continue;
        }
        if (vis[q.X][q.Y]!=-1)
            if (vis[q.X][q.Y]<q.time)
                continue;
            else if (vis[q.X][q.Y]==q.time){
                if (final_grid[q.X][q.Y]!=q.per)
                    final_grid[q.X][q.Y] = '*';
                continue;
            }
        vis[q.X][q.Y] = q.time;
        final_grid[q.X][q.Y] = q.per;
        for (int i=0;i<4;i++){
            int nx = q.X+dx[i], ny = q.Y+dy[i];
            if (nx>=0&&ny>=0&&nx<R&&ny<C&&vis[nx][ny]==-1&&grid[nx][ny]!='#')
                qq.push(mp(nx,ny,q.per,q.time+1,i));
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    char c;
    while(t--){
        scanf("%d %d", &R, &C);
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++){
                vis[i][j] = -1;
                c = getchar();
                if (c=='#'||c=='.'||(c>='a'&&c<='z')){
                    grid[i][j] = c;
                    if (grid[i][j]=='.')
                        final_grid[i][j] = '.';
                    else if (grid[i][j]=='#')
                        final_grid[i][j] = '#';
                    else{
                        final_grid[i][j] = '.';
                        qq.push(mp(i,j,grid[i][j],0,-1));
                    }
                }
                else j--;
            }
        bfs();
        for (int i=0;i<R;i++){
                final_grid[i][C] = '\0';
                printf("%s\n", final_grid[i]);
            }
        printf("\n");
    }
}

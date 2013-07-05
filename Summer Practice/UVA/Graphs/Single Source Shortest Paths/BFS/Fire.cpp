#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Jake pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))
#define Point pair<int, int>

//int fire_grid[1010][1010];
vector<Point> v;
int vis[1010][1010];
//char grid[1010][1010];
int R,C;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

void spread_fire(){
    vector<Point> v1;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<4;j++){
            int nx = v[i].first+dx[j], ny = v[i].second+dy[j];
            if (inside_grid(nx,ny)&&vis[nx][ny]!=2&&vis[nx][ny]!=3){
                vis[nx][ny] = 2;
                v1.push_back(Point(nx,ny));
            }
        }
    }
    v = v1;
}

int bfs(int sx, int sy){
    queue<Jake> q;
    q.push(mp(sx,sy,0));
    int level = 0;
    while(!q.empty()){
        Jake j = q.front();
        q.pop();
        if (!inside_grid(j.X,j.Y))
            return j.cost;
        if (vis[j.X][j.Y]>0)
            continue;
        //printf("%d %d %d\n",j.X,j.Y,j.cost);
        if (j.cost==level){
            spread_fire();
            /*for (int i=0;i<R;i++){
                for (int j=0;j<C;j++)
                    printf("%d ", vis[i][j]);
                printf("\n");
            }*/
            level++;
        }
        vis[j.X][j.Y] = 1;
        for (int i=0;i<4;i++){
            int nx = j.X+dx[i], ny = j.Y+dy[i];
            //if (inside_grid(nx, ny)){
              //  if (!vis[nx][ny])
                    q.push(mp(nx,ny,j.cost+1));
            //}
            //else return j.cost+1;
        }
    }
    return -1;
}

int main(){
    int t,sx,sy;
    scanf("%d", &t);
    while(t--){
        memset(vis, 0, sizeof vis);
        v.clear();
        scanf("%d %d", &R, &C);
        //memset(fire_grid, -1, sizeof fire_grid);
        char grid[1010];
        for (int i=0;i<R;i++){
            scanf("%s", grid);
            for (int j=0;j<C;j++)
                if (grid[j]=='J'){
                    sx = i;
                    sy = j;
                }
                else if (grid[j]=='F'){
                    vis[i][j]=2;
                    v.push_back(Point(i,j));
                }
                else if (grid[j]=='#'){
                    vis[i][j]=3;
                }
        }
        int ans = bfs(sx,sy);
        if (ans==-1)
            printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
}

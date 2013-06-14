#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Point pair<int, pair<int, int> >
#define mp(a,b,c) make_pair(a, make_pair(b, c))
#define X first
#define Y second.first
#define cost second.second

char forest[101][101];
int vis[101][101];

int N, M;

int dx[] = {-2, -2, 1, -1, 2, 2, 1, -1};
int dy[] = {1, -1, -2, -2, 1, -1, 2, 2};

int kx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int ky[] = {1, -1, 0, 0, 1, -1, 1, -1};

int inside_board(int x, int y){
    return x>=0&&y>=0&&x<M&&y<N;
}

void forbidden(){
    for (int i =0;i<M;i++)
        for (int j=0;j<N;j++)
            if (forest[i][j]=='Z'){
                vis[i][j] = 1;
                for (int k=0;k<8;k++)
                    if (inside_board(i+dx[k], j+dy[k])&&forest[i+dx[k]][j+dy[k]]!='A'&&forest[i+dx[k]][j+dy[k]]!='B'){
                        vis[i+dx[k]][j+dy[k]] = 1;
                        //printf("Forbidden: %d %d\n", i+dx[k], j+dy[k]);
                    }
            }
}


int bfs(int x, int y, int desx, int desy){
    queue<Point> q;
    q.push(mp(x,y,0));
    while (!q.empty()){
        Point p = q.front();
        q.pop();
        if (p.X==desx&&p.Y==desy)
            return p.cost;
        if (vis[p.X][p.Y])
            continue;
        vis[p.X][p.Y] = 1;
        for (int i =0;i<8;i++){
            int nx = p.X+kx[i], ny = p.Y+ky[i];
            if (inside_board(nx, ny))
                q.push(mp(nx, ny, p.cost+1));
        }
    }
    return -1;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &M, &N);
        memset(vis, 0, sizeof vis);
        for (int i= 0;i<M;i++)
            scanf("%s", forest[i]);
        int Ax, Ay, Bx, By;
        for (int i =0;i<M;i++)
            for (int j =0;j<N;j++)
                if (forest[i][j]=='A'){
                    Ax = i;
                    Ay = j;
                }
                else if (forest[i][j]=='B'){
                    Bx = i;
                    By = j;
                }
        forbidden();
        int dis = bfs(Ax, Ay, Bx, By);
        if (dis==-1)
            printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n", dis);
    }
}

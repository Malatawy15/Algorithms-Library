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

int inside_board(int x, int y){
    return x>=0&&y>=0&&x<8&&y<8;
}

int dx[] = {-2, -2, 1, -1, 2, 2, 1, -1};
int dy[] = {1, -1, -2, -2, 1, -1, 2, 2};

int bfs(int x, int y, int desx, int desy){
    queue<Point> q;
    q.push(mp(x,y,0));
    int vis[8][8];
    memset(vis, 0, sizeof vis);
    while (!q.empty()){
        Point p = q.front();
        q.pop();
        if (p.X==desx&&p.Y==desy)
            return p.cost;
        if (vis[p.X][p.Y])
            continue;
        vis[p.X][p.Y] = 1;
        for (int i =0;i<8;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (inside_board(nx, ny))
                q.push(mp(nx, ny, p.cost+1));
        }
    }
    return -1;
}

int main(){
    char str[20], str1[20];
    while (scanf("%s %s", str, str1)>0)
        printf("To get from %c%c to %c%c takes %d knight moves.\n", str[0], str[1], str1[0], str1[1], bfs(str[1]-'1', str[0]-'a', str1[1]-'1', str1[0]-'a'));
}

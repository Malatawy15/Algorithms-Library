#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define State pair<pair<int, int>, pair<int, int> >
#define Z first.first
#define X first.second
#define Y second.first
#define C second.second
#define mp(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))

int L, H, W, N, S;
char grid[11][101][101];
int vis[11][101][101];
int vals[101][2];
int dp[101][10011];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(){
    int sx, sy;
    for (int i=0;i<H;i++)
        for (int j=0;j<W;j++)
            if (grid[0][i][j]=='S'){
                sx = i, sy = j;
                break;
            }
    queue<State> q;
    memset(vis,-1,sizeof vis);
    q.push(mp(0,sx,sy,0));
    while(!q.empty()){
        State s = q.front();
        q.pop();
        if (grid[s.Z][s.X][s.Y]=='X'||vis[s.Z][s.X][s.Y]!=-1)
            continue;
        vis[s.Z][s.X][s.Y] = s.C;
        for (int i=0;i<4;i++){
            int nx = s.X+dx[i], ny = s.Y+dy[i];
            if (nx>=0&&nx<H&&ny>=0&&ny<W)
                q.push(mp(s.Z, nx, ny, s.C+1));
        }
        if (grid[s.Z][s.X][s.Y]=='U'){
            q.push(mp(s.Z+1, s.X, s.Y, s.C+1));
        }
        else if (grid[s.Z][s.X][s.Y]=='D'){
            q.push(mp(s.Z-1, s.X, s.Y, s.C+1));
        }
    }
}

int maximize(int n, int rem){
    if (rem<0)
        return -10000000;
    if (n==N)
        return 0;
    if (dp[n][rem]!=-1)
        return dp[n][rem];
    dp[n][rem] = 0;
    dp[n][rem] = max(dp[n][rem],maximize(n+1,rem));
    if (rem-vals[n][0]>=0)
        dp[n][rem] = max(dp[n][rem],vals[n][1]+maximize(n+1,rem-vals[n][0]));
    return dp[n][rem];
}

int main(){
    int t,x,y,z,p;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &L, &H, &W, &N, &S);
        for (int i=0;i<L;i++)
            for (int j=0;j<H;j++)
                scanf("%s", grid[i][j]);
        bfs();
        for (int i=0;i<N;i++){
            scanf("%d %d %d %d", &z,&x,&y,&p);
            z--;x--;y--;
            if (vis[z][x][y]==-1){
                vals[i][0] = 10000000;
            }
            else {
                vals[i][0] = vis[z][x][y]+2*vis[z][x][y];
            }
            vals[i][1] = p;
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n", maximize(0,S));
    }
}

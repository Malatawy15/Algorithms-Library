#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int R, C, N;
int sd [12][12];
int ind [12][2];
char grid[25][25];
int vis[25][25];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(int n){
    queue<Point > q;
    memset(vis,0,sizeof vis);
    q.push(mp(ind[n][0], ind[n][1],0));
    int tbv = 0;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (vis[p.X][p.Y]||grid[p.X][p.Y]=='x')
            continue;
        vis[p.X][p.Y] = 1;
        if (grid[p.X][p.Y]>='0'&&grid[p.X][p.Y]<='9'){
            sd[n][grid[p.X][p.Y]-'0'+1] = p.cost;
            tbv++;
        }
        if (grid[p.X][p.Y]=='o'){
            sd[n][0] = p.cost;
            tbv++;
        }
        for (int i=0;i<4;i++){
            int nx = p.X + dx[i],ny = p.Y + dy[i];
            if (nx>=0&&ny>=0&&nx<R&&ny<C&&grid[nx][ny]!='x'&&!vis[nx][ny])
                q.push(mp(nx,ny,p.cost+1));
        }
    }
    if (tbv==N)
        return 1;
    else return 0;
}

int dp[12][8000];


int minimize(int n, int bitmask){
    if (bitmask==(1<<N)-1)
        return 0;
    if (dp[n][bitmask]!=-1)
        return dp[n][bitmask];
    dp[n][bitmask] = 100000000;
    int nb = bitmask|(1<<n);
    for (int i=0;i<N;i++){
        if (!(bitmask&(1<<i)))
            dp[n][bitmask] = min(dp[n][bitmask], sd[n][i]+minimize(i,nb));
    }
    return dp[n][bitmask];
}


int compute (){
    for (int i=0;i<N;i++)
        if (!bfs(i))
            return -1;
    memset(dp, -1, sizeof dp);
    return minimize(0,0);
}

int main(){
    scanf("%d %d", &C, &R);
    while(!(!R&&!C)){
        N = 1;
        for (int i=0;i<R;i++){
            scanf("%s", grid[i]);
            for (int j=0;j<C;j++)
                if (grid[i][j]=='*'){
                    grid[i][j] = '0'+N-1;
                    ind[N][0] = i;
                    ind[N][1] = j;
                    N++;
                }
                else if (grid[i][j]=='o'){
                    ind[0][0] = i;
                    ind[0][1] = j;
                }
        }
        printf("%d\n",compute());
        scanf("%d %d", &C, &R);
    }
}

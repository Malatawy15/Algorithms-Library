#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define Point pair<int, pair<int, pair<int, int> > >
#define X first
#define Y second.first
#define mm second.second.first
#define tm second.second.second
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))


typedef bool(*CompareFunc)(Point, Point);

bool Compare(Point p1, Point p2){
    if (p1.mm<p2.mm)
        return 0;
    else if (p1.mm>p2.mm)
        return 1;
    else if (p1.tm>p2.tm)
        return 0;
    else return 1;
}

int N,T;
int tms[21][21];
int mms[21][21];
int vis[21][21];
int grid[21][21];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dij(){
    priority_queue<Point, vector<Point>, CompareFunc> pq(Compare);
    memset(vis,0,sizeof vis);
    pq.push(mp(0,0,grid[0][0],T-grid[0][0]));
    while(!pq.empty()){
        Point p = pq.top();
        pq.pop();
        if (p.tm<0)
            continue;
        if (p.X==N-1&&p.Y==N-1){
            printf("YES : %d %d\n", p.mm, p.tm);
            return;
        }
        if (vis[p.X][p.Y]){
            if (mms[p.X][p.Y]<p.mm)
                continue;
            if (mms[p.X][p.Y]==p.mm&&tms[p.X][p.Y]>=p.tm)
                continue;
        }
        vis[p.X][p.Y] = 1;
        mms[p.X][p.Y] = p.mm;
        tms[p.X][p.Y] = p.tm;
        for (int i=0;i<4;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (nx>=0&&ny>=0&&nx<N&&ny<N)
                if (p.tm>=abs(grid[p.X][p.Y]-grid[nx][ny]))
                    pq.push(mp(nx,ny,max(p.mm, grid[p.X][p.Y]-grid[nx][ny]),p.tm-abs(grid[p.X][p.Y]-grid[nx][ny])));
        }
    }
    printf("NO\n");
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &T);
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                scanf("%d", &grid[i][j]);
        dij();
    }
}

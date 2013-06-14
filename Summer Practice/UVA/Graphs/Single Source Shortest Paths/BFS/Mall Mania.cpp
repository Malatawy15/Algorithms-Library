#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;

#define Point pair<int, int>
#define X first
#define Y second

#define Pointy pair<int, pair<int, int> >
#define cX first
#define cY second.first
#define cost second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

vector<Point> v;
set<Point> v1;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(){
    queue<Pointy> q;
    for (int i=0;i<v.size();i++)
        q.push(mp(v[i].X, v[i].Y, 0));
    int vis[2010][2010];
    memset(vis, 0, sizeof vis);
    while(!q.empty()){
        Pointy p = q.front();
        q.pop();
        Point p1=Point(p.cX, p.cY);
        printf("%d %d\n", p1.X, p1.Y);
        if (vis[p1.X][p1.Y])
            continue;
        if (v1.count(p1)>0)
            return p.cost;
        vis[p1.X][p1.Y] = 1;
        for (int i =0;i<4;i++){
            int nx = p1.X+dx[i], ny = p1.Y+dy[i];
            if (nx>=0&&nx<=2000&&ny>=0&&ny<=2000){
                //printf("INSERT: %d %d\n", nx, ny);
                q.push(mp(nx, ny, p.cost+1));
            }
        }
    }
    return -1;
}

int main(){
    int p,x,y,minimum = 100000000;
    scanf("%d", &p);
    while(p){
        v.clear();
        v1.clear();
        for (int i=0;i<p;i++){
            scanf ("%d %d", &x, &y);
            v.push_back(Point(x,y));
        }
        scanf("%d", &p);
        for (int i=0;i<p;i++){
            scanf ("%d %d", &x, &y);
            v1.insert(Point(x,y));
        }
        printf("%d\n",bfs());
        scanf("%d", &p);
    }
}

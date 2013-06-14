#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include <sstream>

using namespace std;

#define Point pair<int, int>
#define num first
#define cost second

int L, U, R;

int vis [10000];
int rs [10000];

int bfs(){
    memset(vis, 0, sizeof vis);
    queue<Point> q;
    q.push(Point(L, 0));
    while (!q.empty()){
        Point p = q.front();
        q.pop();
        if (p.num==U)
            return p.cost;
        if (vis[p.num])
            continue;
        vis[p.num] = 1;
        for (int i =0;i<R;i++){
            int nn = (p.num+rs[i])%10000;
            if (!vis[nn])
                q.push(Point(nn, p.cost+1));
        }
    }
    return -1;
}

int main(){
    int cases = 1;
    scanf("%d %d %d", &L, &U, &R);
    while(!(L==0&&U==0&&R==0)){
        for (int i=0;i<R;i++)
            scanf("%d", &rs[i]);
        int x = bfs();
        if (x==-1)
            printf("Case %d: Permanently Locked\n", cases++);
        else printf("Case %d: %d\n", cases++, x);
        scanf("%d %d %d", &L, &U, &R);
    }
}

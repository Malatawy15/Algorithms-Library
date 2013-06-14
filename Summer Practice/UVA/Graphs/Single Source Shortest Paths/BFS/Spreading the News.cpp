#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Point pair<int, int>
#define id first
#define day second

vector<int> conn[2510];
int vis[2510];

Point bfs(int s){
    memset(vis, 0, sizeof vis);
    queue<Point> q;
    int max = 0, theday = 0, cday = 0, sum = -1;
    q.push(Point(s, 0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (p.day!=cday){
            if (sum>max){
                max = sum;
                theday = cday;
            }
            cday = p.day;
            sum = 0;
        }
        if (vis[p.id])
            continue;
        sum++;
        vis[p.id] = 1;
        for (int i =0;i<conn[p.id].size();i++)
            q.push(Point(conn[p.id][i], p.day+1));
    }
    if (sum>max){
        max = sum;
        theday = cday;
    }
    return Point(max, theday);
}

int main(){
    int E, N, T;
    scanf("%d", &E);
    for (int i =0;i<E;i++){
        scanf("%d", &N);
        for (int j=0;j<N;j++){
            scanf("%d", &T);
            conn[i].push_back(T);
        }
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        Point ans = bfs(N);
        if (ans.id==0)
            printf("%d\n", 0);
        else printf("%d %d\n", ans.id, ans.day);
    }
}

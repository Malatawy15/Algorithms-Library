#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Lights pair<int, int>
#define lamps first
#define cost second

int N, M;

int switches[101];

int bfs(){
    int vis[1<<N];
    memset(vis, 0, sizeof vis);
    queue<Lights> q;
    int target = (1<<N)-1;
    q.push(Lights(0,0));
    while(!q.empty()){
        Lights l = q.front();
        q.pop();
        if (vis[l.lamps])
            continue;
        if (l.lamps==target)
            return l.cost;
        vis[l.lamps] = 1;
        for (int i =0;i<M;i++){
            q.push(Lights(l.lamps^switches[i],l.cost+1));
        }
    }
    return -1;
}

int main(){
    int t, r;
    scanf("%d", &t);
    for (int k=1;k<=t;k++){
        scanf("%d %d", &N, &M);
        for (int i=0;i<M;i++){
            switches[i] = 0;
            for (int j=N-1;j>=0;j--){
                scanf("%d", &r);
                switches[i]|=(r<<j);
            }
        }
        int x = bfs();
        if (x==-1)
            printf("Case %d: IMPOSSIBLE\n", k);
        else
            printf("Case %d: %d\n", k, x);
    }
}


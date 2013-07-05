#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Hole pair<int, int>
#define id first
#define cost second

double holes[1000][2];
int vis[1000];

int n;
double dis;

int bfs(){
    memset(vis, 0, sizeof vis);
    queue<Hole> q;
    q.push(Hole(0,0));
    while(!q.empty()){
        Hole h = q.front();
        q.pop();
        if (holes[h.id][0]==holes[1][0]&&holes[h.id][1]==holes[1][1])
            return h.cost;
        if (vis[h.id])
            continue;
        vis[h.id] = 1;
        for (int i=0;i<n;i++)
            if (!vis[i]&&(holes[h.id][0]-holes[i][0])*(holes[h.id][0]-holes[i][0])+(holes[h.id][1]-holes[i][1])*(holes[h.id][1]-holes[i][1])<=dis)
                q.push(Hole(i,h.cost+1));
    }
    return -1;
}

int main(){
    int v, m;
    double x,y;
    scanf("%d %d",&v,&m);
    while(!(v==0&&m==0)){
        n = 0;
        dis = v*m*60;
        dis*=dis;
        char buf1[100];
        gets(buf1);
        int res=2;
        while (res == 2){
            char buf[100];
            fgets(buf, sizeof(buf), stdin);
            res = sscanf(buf, "%lf %lf", &holes[n][0], &holes[n][1]);
            n++;
        }
        n--;
        int ans = bfs();
        if (ans==-1)
            printf("No.\n");
        else printf("Yes, visiting %d other holes.\n", ans-1);
        scanf("%d %d",&v,&m);
    }
}

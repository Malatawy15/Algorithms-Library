#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

#define Floor pair<int, int>
#define floor first
#define cost second

int main(){
    int f,s,g,u,d;
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    int vis[f+1];
    memset(vis,0,sizeof vis);
    queue<Floor> q;
    q.push(Floor(s,0));
    while(!q.empty()){
        Floor fl = q.front();
        q.pop();
        if (fl.floor==g){
            printf("%d\n",fl.cost);
            return 0;
        }
        if (vis[fl.floor])
            continue;
        vis[fl.floor] = 1;
        if (fl.floor-d>0){
            if (fl.floor-d==g){
                printf("%d\n",fl.cost+1);
                return 0;
            }
            q.push(Floor(fl.floor-d,fl.cost+1));
        }
        if (fl.floor+u<=f){
            if (fl.floor+u==g){
                printf("%d\n",fl.cost+1);
                return 0;
            }
            q.push(Floor(fl.floor+u,fl.cost+1));
        }
    }
    printf("use the stairs\n");
}

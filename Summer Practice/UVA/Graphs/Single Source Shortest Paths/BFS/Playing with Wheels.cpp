#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define r(a) ((a+1)%10)
#define l(a) (((a-1)+10)%10)
#define Config pair<int, pair<int, pair<int, pair<int,int> > > >
#define w1 first
#define w2 second.first
#define w3 second.second.first
#define w4 second.second.second.first
#define cost second.second.second.second
#define mp(a,b,c,d,e) make_pair(a, make_pair(b, make_pair(c, make_pair(d,e))))

int i1, i2, i3, i4, f1, f2, f3, f4;
int vis[10][10][10][10];

int bfs(){
    queue<Config> q;
    q.push(mp(i1,i2,i3,i4,0));
    while(!q.empty()){
        Config c = q.front();
        q.pop();
        if (vis[c.w1][c.w2][c.w3][c.w4])
            continue;
        if (c.w1==f1&&c.w2==f2&&c.w3==f3&&c.w4==f4)
            return c.cost;
        vis[c.w1][c.w2][c.w3][c.w4] = 1;
        q.push(mp(l(c.w1),c.w2,c.w3,c.w4,c.cost+1));
        q.push(mp(r(c.w1),c.w2,c.w3,c.w4,c.cost+1));
        q.push(mp(c.w1,l(c.w2),c.w3,c.w4,c.cost+1));
        q.push(mp(c.w1,r(c.w2),c.w3,c.w4,c.cost+1));
        q.push(mp(c.w1,c.w2,l(c.w3),c.w4,c.cost+1));
        q.push(mp(c.w1,c.w2,r(c.w3),c.w4,c.cost+1));
        q.push(mp(c.w1,c.w2,c.w3,l(c.w4),c.cost+1));
        q.push(mp(c.w1,c.w2,c.w3,r(c.w4),c.cost+1));
    }
    return -1;
}


int main(){
    int t,n,n1,n2,n3,n4;
    scanf("%d",&t);
    while(t--){
        memset(vis, 0, sizeof vis);
        scanf("%d %d %d %d",&i1,&i2,&i3,&i4);
        scanf("%d %d %d %d",&f1,&f2,&f3,&f4);
        scanf("%d",&n);
        while(n--){
            scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
            vis[n1][n2][n3][n4] = 1;
        }
        printf("%d\n",bfs());
    }
}

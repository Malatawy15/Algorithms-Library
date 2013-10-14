#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

struct Road{
    int id, cst, hgt;
    bool operator< (const Road &r) const{
        if (hgt!=r.hgt)
            return hgt<r.hgt;
        else return cst>r.cst;
    }
};

Road create(int o1, int o2, int o3){
    Road r;
    r.id = o1;
    r.cst = o2;
    r.hgt = o3;
    return r;
}

int C, R, S, D, H, cs;
vector <Road> graph[1001];
int vis[1001];

void dij(){
    priority_queue<Road> pq;
    memset(vis, -1, sizeof vis);
    pq.push(create(S,0,H));
    printf("Case %d:\n",cs++);
    while(!pq.empty()){
        Road r = pq.top();
        pq.pop();
        if (r.id==D){
            printf("maximum height = %d\n",r.hgt);
            printf("length of shortest route = %d\n",r.cst);
            return;
        }
        if (vis[r.id]!=-1&&vis[r.id]<=r.hgt)
            continue;
        vis[r.id] = 1;
        for (int i=0;i<graph[r.id].size();i++){
            Road rr = graph[r.id][i];
            pq.push(create(rr.id,rr.cst+r.cst,min(rr.hgt, r.hgt)));
        }
    }
    printf("cannot reach destination\n");
}

int main(){
    freopen("trucking.in","r", stdin);
    freopen("out.txt","w", stdout);
    cs = 1;
    int a,b,c,d, flag = 0;
    scanf("%d %d", &C, &R);
    while(!(C==0&&R==0)){
        //printf("R: %d C: %d\n",R,C);
        if (flag)
            printf("\n");
        else flag = 1;
        for (int i=0;i<R;i++){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if (c==-1){
                graph[a].push_back(create(b,d,1000000000));
                graph[b].push_back(create(a,d,1000000000));
            }
            else{
                graph[a].push_back(create(b,d,c));
                graph[b].push_back(create(a,d,c));
            }
        }
        scanf("%d %d %d", &S, &D, &H);
        dij();
        for (int i=0;i<=C;i++)
            graph[i].clear();
        scanf("%d %d", &C, &R);
    }
}

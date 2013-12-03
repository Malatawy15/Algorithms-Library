#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX_N = 202;

int N, mf, f, s, t, cf;

int res[MAX_N][MAX_N];
vector<int> p;

void augment(int v, int mE){
    if (v==s){
        f = mE;
        return;
    }
    if (p[v]!=-1){
        augment(p[v], min(mE, res[p[v]][v]));
        res[p[v]][v]-=f;res[v][p[v]]+=f;
    }
}

int main(){
    int tt,a,b;
    scanf("%d", &tt);
    while(tt--){
        mf = 0;
        memset(res,0,sizeof res);
        scanf("%d", &N);
        scanf("%d", &a);
        cf = a;
        for (int i=0;i<a;i++){
            scanf("%d", &b);
            res[1][b] = 1;
        }
        for (int i=2;i<N;i++){
            scanf("%d", &a);
            for (int j=0;j<a;j++){
                scanf("%d", &b);
                if (b!=N)
                    res[i][b] = cf;
                else res[i][b] = 1;
            }
        }
        s = 1;
        t = N;
        while(1){
            f = 0;
            vector<int> dist(MAX_N, 100000000);
            dist[s] = 0;
            queue<int>q;
            q.push(s);
            p.assign(MAX_N,-1);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if (u==t) break;
                for (int v = 0;v<=N;v++){
                    if (res[u][v]>0&&dist[v]==100000000)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                }
            }
            augment(t, 100000000);
            if (!f) break;
            mf+=f;
        }
        printf("%d\n", mf);
    }
}

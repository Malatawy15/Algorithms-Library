#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int M, N, mf, f, s, t;
//char grid [31][31];
vector<string> grid;
int res [2000][2000];

vector<int> p;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void construct(){
    s = 2*M*N;
    t = 2*M*N+1;
    int out = M*N;
    for (int i=0;i<M;i++)
    for (int j=0;j<N;j++){
        int ind = i*N+j;
        res[ind][ind+out] = 1;
        if (grid[i][j]=='W')
            res[s][ind] = 1;
        if (grid[i][j]=='N'){
            res[ind+out][t] = 1;
            //continue;
        }
        for (int k=0;k<4;k++){
            int nx = i+dx[k], ny=j+dy[k];
            if (nx<0||ny<0||nx>=M||ny>=N)
                continue;
            if (grid[i][j]=='W'&&grid[nx][ny]=='I')
                res[ind+out][nx*N+ny] = 1;
            if (grid[i][j]=='I'&&grid[nx][ny]=='N')
                res[ind+out][nx*N+ny] = 1;
        }
    }
    /*
    printf("RES: \n");
    for (int i=0;i<M*N+2;i++){
        for (int j=0;j<M*N+2;j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    */
}

void augment(int v, int mE){
    if (v==s) {
        f = mE;
        return;
    }
    else if (p[v] != -1){
        augment(p[v],min(mE, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main(){
    freopen("TileCut.in","r",stdin);
    freopen("out.txt","w",stdout);
    while (true) {
        grid.clear();
        string st;
        while (getline(cin, st)) {
          if (st.length() == 0) break;
          grid.push_back(st);
        }
        if (grid.size() == 0) break;
        M = grid.size();
        N = grid[0].size();
        memset(res,0,sizeof res);
        construct();
        mf = 0;
        int mv = 2*M*N+2;
        while(1){
            f = 0;
            vector<int> dist(mv,1000000000);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(mv, -1);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if (u==t) break;
                for (int v=0;v<mv;v++){
                    if (res[u][v]>0 &&dist[v] == 1000000000)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                }
            }
            augment(t,1000000000);
            if (f==0) break;
            mf+=f;
        }
        printf("%d\n", mf);
        //cout << solve() << endl;
      }
  return 0;
}

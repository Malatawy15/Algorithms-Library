#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define level second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

vector<vector<string> > patterns;
int R, C, P;
int vis[21][21][11];

int dx[]={1,0,-1,0,0};
int dy[]={0,1,0,-1,0};


int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

int bfs(){
    queue<Point> q;
    memset(vis, 0, sizeof vis);
    q.push(mp(0,0,0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (patterns[p.level%P][p.X][p.Y]=='1')
            continue;
        if (p.X==R-1&&p.Y==C-1)
            return p.level;
        if (vis[p.X][p.Y][p.level%P])
            continue;
        vis[p.X][p.Y][p.level%P] = 1;
        for (int i=0;i<5;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (inside_grid(nx,ny))
                q.push(mp(nx,ny,p.level+1));
        }
    }
    return -1;
}

int main(){
    string in;
    cin>>R>>C>>P;
    int cases = 1;
    while(!(!R&&!C&&!P)){
        for (int k=0;k<P;k++){
            vector<string> vec;
            for (int i=0;i<R;i++){
                cin>>in;
                vec.push_back(in);
            }
            patterns.push_back(vec);
        }
        int ans = bfs();
        if (ans==-1)
            printf("Case %d: Luke and Leia cannot escape.\n",cases++);
        else printf("Case %d: Luke and Leia can escape in %d steps.\n",cases++,ans);
        patterns.clear();
        cin>>R>>C>>P;
    }
}

/*
ACPC11D
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<string>

using namespace std;

#define State pair<int, pair<int, int> >
#define cost first
#define X second.first
#define Y second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

int N, M, ans, score, ts;
char grid[11][11];
int rS[11][11];
int rD[11][11];
int vis[11][11];
int bef[11][11];
int dis[11][11];
char buf [10];
string st;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

string transform_state(string s, int t, int x, int y){
    score = 0;
    char res [6];
    if (t==0){
        res[0] = s[4];
        res[1] = s[5];
        res[2] = s[2];
        res[3] = s[3];
        res[4] = s[1];
        res[5] = s[0];
    }
    else if (t==1){
        res[0] = s[5];
        res[1] = s[4];
        res[2] = s[2];
        res[3] = s[3];
        res[4] = s[0];
        res[5] = s[1];
    }
    else if (t==2){
        res[0] = s[0];
        res[1] = s[1];
        res[2] = s[5];
        res[3] = s[4];
        res[4] = s[2];
        res[5] = s[3];
    }
    else if (t==3){
        res[0] = s[0];
        res[1] = s[1];
        res[2] = s[4];
        res[3] = s[5];
        res[4] = s[3];
        res[5] = s[2];
    }
    if (grid[x][y]=='T')
    	score = 0;
    else if (res[5]==grid[x][y]){
        score = (res[5]-'0')<<1;
        //printf("SET SCORE: %d %d %d\n",x,y,score);
    }
    else {
        score = -1*((res[5]-'0')+(grid[x][y]-'0'));
    }
    return string(res);
}

void dfs(int x, int y, string s, int sc){
	//printf("Call: %d %d %d\n",x,y,sc);
    if (ans)
        return;
    if (!vis[x][y]&&bef[x][y]&&dis[x][y]>=sc)
        return;
    if (grid[x][y]=='S'){
    	if (ts)
    		return;
    	else ts = 1;
    }
    if (vis[x][y]&&sc>dis[x][y]&&rD[x][y]){
        ans = 1;
        return;
    }
    if (vis[x][y])
        return;
    dis[x][y] = sc;
    //printf("SET DIS: %d %d %d\n",x,y,dis[x][y]);
    bef[x][y] = 1;
    if (grid[x][y]=='T')
        return;
    vis[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<N&&ny<M&&grid[nx][ny]!='.'){
        	string ss = transform_state(s,i,nx,ny);dfs(nx,ny,ss,sc+score);
        }

    }
    vis[x][y] = 0;
}

void dfs_source(int x, int y){
    if (rS[x][y])
        return;
    rS[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<N&&ny<M&&grid[nx][ny]!='.')
            dfs_source(nx,ny);
    }
}

void dfs_des(int x, int y){
    if (rD[x][y])
        return;
    rD[x][y] = 1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<N&&ny<M&&grid[nx][ny]!='.')
            dfs_des(nx,ny);
    }
}

int main(){
	    freopen("dice.in","r",stdin);
    freopen("dice.txt","w",stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &M);
        scanf("%s", buf);
        st = string(buf);
        for (int i=0;i<N;i++)
            scanf("%s", grid[i]);
        ans = 0;
        int sx, sy, ex, ey;
        memset(rS,0,sizeof rS);
        memset(rD,0,sizeof rD);
        ts = 0;
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                if (grid[i][j]=='S'){
                    sx = i;sy = j;
                }
                else if (grid[i][j]=='T'){
                    ex = i;ey = j;
                }
        //printf("COOD: %d %d %d %d\n",sx,sy,ex,ey);
        dfs_source(sx,sy);
        if (!rS[ex][ey]){
            printf("Impossible\n");
            continue;
        }
        dfs_des(ex,ey);
        memset(bef,0,sizeof bef);
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        dfs(sx,sy,st,0);
        if (ans){
            printf("Infinity\n");
        }
        else printf("%d\n", dis[ex][ey]);
    }
}

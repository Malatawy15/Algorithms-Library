#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int N, M, cn;
char grid[25][25];
int col[25][25];
int vis[20][20][64][64][6][4];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct state{
    int x, y, b_grid, b_cube, steps;
    string st;
    state(int xx, int yy, int bg, int bc, string s, int step){
        x = xx;
        y = yy;
        b_grid = bg;
        b_cube = bc;
        st = s;
        steps = step;
    }
};

int get_state_number(int bot, int north){
    if (bot==0||bot==1)
        return north-2;
    if (bot==2||bot==3){
        if (north>2)
            return north-2;
        else return north;
    }
    if (bot==4||bot==5)
        return north;
}

int bfs(int sx, int sy){
    queue<state> q;
    int sss;
    q.push(state(sx,sy,0,0,"012345",0));
    vis[sx][sy][0][0][5][2] = cn;
    while(!q.empty()){
        state s = q.front();q.pop();
        //printf("STATE: %d %d %d %d %s %d\n", s.x,s.y,s.b_grid,s.b_cube,s.st.c_str(),s.steps);
        //scanf("%d", &sss);
        if (grid[s.x][s.y]=='G'&&s.b_grid==63&&s.b_cube==63)
            return s.steps;
        for (int i=0;i<4;i++){
            int nx = s.x+dx[i], ny = s.y+dy[i];
            if (nx<0||ny<0||nx>=M||ny>=N)
                continue;
            if (grid[nx][ny]=='#')
                continue;
            string ns = "";
            if (i==0){
                ns+=s.st[4];
                ns+=s.st[5];
                ns+=s.st[2];
                ns+=s.st[3];
                ns+=s.st[1];
                ns+=s.st[0];
            }
            else if (i==1){
                ns+=s.st[5];
                ns+=s.st[4];
                ns+=s.st[2];
                ns+=s.st[3];
                ns+=s.st[0];
                ns+=s.st[1];
            }
            else if (i==2){
                ns+=s.st[0];
                ns+=s.st[1];
                ns+=s.st[5];
                ns+=s.st[4];
                ns+=s.st[2];
                ns+=s.st[3];
            }
            else {
                ns+=s.st[0];
                ns+=s.st[1];
                ns+=s.st[4];
                ns+=s.st[5];
                ns+=s.st[3];
                ns+=s.st[2];
            }
            int dn = (ns[5]-'0'), nr = (ns[2]-'0');
            int fr = get_state_number(dn,nr), nbg = s.b_grid, nbc = s.b_cube;
            if (grid[nx][ny]=='P'){
                if (!(nbc&(1<<dn))&&!(nbg&(1<<col[nx][ny]))){
                    nbc|=(1<<dn);
                    nbg|=(1<<col[nx][ny]);
                }
                else if (!(nbc&(1<<dn))&&(nbg&(1<<col[nx][ny]))){
                    continue;
                }
            }
            if (vis[nx][ny][nbg][nbc][dn][fr])
                continue;
            vis[nx][ny][nbg][nbc][dn][fr] = 1;
            q.push(state(nx,ny,nbg,nbc,ns,s.steps+1));
        }
    }
    return -1;
}

int main(){
    cn = 1;
    M = 0;
    while(gets(grid[M++])){
        int f = 0;
        while(1){
            if (!gets(grid[M])){
                f = 1;break;
            }
        	if (strcmp(grid[M],"")==0){
        		break;
        	}
   			M++;
        }
        N = strlen(grid[0]);
        //printf("M: %d----N: %d\n", M, N);
        int sx, sy, ind = 0;
        for (int i=0;i<M;i++)
            for (int j=0;j<N;j++)
                if (grid[i][j]=='C')
                    sx = i, sy = j;
                else if (grid[i][j]=='P')
                    col[i][j] = ind++;
        printf("%d\n", bfs(sx,sy));
        M = 0;
        cn++;
        if (f)
            break;
    }
}

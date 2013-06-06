#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N, M, E;

char grid [11][11];
int vis [11][11];

//Move North-East-South-West
int dx [] = {-1,0,1,0};
int dy [] = {0,1,0,-1};


int out_or_loop(int x, int y){
    if (x<0 || y<0 || x>=N || y>=M)
        return 0;
    else if (vis[x][y] != 0)
        return 1;
    else return 2;
}

void trace_robot(int sx, int sy){
    memset(vis, 0, sizeof vis);
    int sum = 1;
    while (out_or_loop(sx, sy)==2){
        vis[sx][sy] = sum++;
        switch(grid[sx][sy]){
            case 'N': sx+= dx[0]; sy+= dy[0]; break;
            case 'E': sx+= dx[1]; sy+= dy[1]; break;
            case 'S': sx+= dx[2]; sy+= dy[2]; break;
            case 'W': sx+= dx[3]; sy+= dy[3]; break;
        }
    }
    if (out_or_loop(sx, sy) == 0){
        printf("%d step(s) to exit\n", sum-1);
    }
    else{
        printf("%d step(s) before a loop of %d step(s)\n", vis[sx][sy]-1, sum-vis[sx][sy]);
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &E);
    while (!(N==0&&M==0&&E==0)){
        for (int i =0;i<N; i++){
            scanf("%s", grid[i]);
        }
        trace_robot(0, E-1);
        scanf("%d %d %d", &N, &M, &E);
    }
}

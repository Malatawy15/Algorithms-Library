#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define R(x) ((x+5)%4)
#define L(x) ((x+3)%4)


int N, M, S;

int vis [101][101];
char ins [101];

//Move North-East-South-West
int dx [] = {0,1,0,-1};
int dy [] = {1,0,-1,0};

int can_move(int x, int y){
    if (x<0)
        if (vis[x+1][y])
            return 1;
        else {
            vis[x+1][y] = 1;
            return 0;
        }
    else if (y<0)
        if (vis[x][y+1])
            return 1;
        else {
            vis[x][y+1] = 1;
            return 0;
        }
    else if (x>N)
        if (vis[x-1][y])
            return 1;
        else {
            vis[x-1][y] = 1;
            return 0;
        }
    else if (y>M)
        if (vis[x][y-1])
            return 1;
        else {
            vis[x][y-1] = 1;
            return 0;
        }
    else return 2;
}

void trace_robot(int sx, int sy, int o){
    S = strlen(ins);
    for (int i =0;i<S;i++){
        switch(ins[i]){
            case 'L': o = L(o); break;
            case 'R': o = R(o); break;
            case 'F':
                int can = can_move(sx+dx[o], sy+dy[o]);
                if (can==2){
                    sx += dx[o];
                    sy += dy[o];
                }
                else if (can==0){
                    printf("%d %d %c LOST\n", sx, sy, o==0?'N':o==1?'E':o==2?'S':'W');
                    return;
                }
                break;
        }
    }
    printf("%d %d %c\n", sx, sy, o==0?'N':o==1?'E':o==2?'S':'W');
}

int main(){
    memset(vis, 0, sizeof vis);
    int sx, sy, o;
    char c;
    scanf("%d %d", &N, &M);
    while (scanf("%d %d %c", &sx, &sy, &c)>0){
        switch (c){
            case 'N': o = 0; break;
            case 'E': o = 1; break;
            case 'S': o = 2; break;
            case 'W': o = 3; break;
        }
        scanf("%s", ins);
        trace_robot(sx, sy, o);
    }
}

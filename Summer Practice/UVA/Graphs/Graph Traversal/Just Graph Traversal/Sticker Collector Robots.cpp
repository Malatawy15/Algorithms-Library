#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define D(x) ((x+5)%4)
#define E(x) ((x+3)%4)


int N, M, S;

char arena [101][101];
char ins [60000];

//Move North-East-South-West
int dx [] = {-1,0,1,0};
int dy [] = {0,1,0,-1};

int can_move(int x, int y){
    if (x<0 || y<0 || x>=N || y>=M || arena[x][y]=='#')
        return 0;
    else return 1;
}

int num_stickers(int sx, int sy, int o){
    int sum = 0;
    for (int i =0;i<S;i++){
        switch(ins[i]){
            case 'D': o = D(o); break;
            case 'E': o = E(o); break;
            case 'F':
                if (can_move(sx+dx[o], sy+dy[o])){
                    sx += dx[o];
                    sy += dy[o];
                    if (arena[sx][sy]=='*'){
                        sum++;
                        arena[sx][sy] = '.';
                    }
                }
                break;
        }
    }
    return sum;
}

int main(){
    int sx, sy, o;
    scanf("%d %d %d", &N, &M, &S);
    while (!(N==0&&M==0&&S==0)){
        for (int i =0;i<N; i++){
            scanf("%s", arena[i]);
        }
        for (int i =0;i<N;i++){
            for (int j=0;j<M;j++){
                switch (arena[i][j]){
                    case 'N': sx = i; sy = j; o = 0; break;
                    case 'L': sx = i; sy = j; o = 1; break;
                    case 'S': sx = i; sy = j; o = 2; break;
                    case 'O': sx = i; sy = j; o = 3; break;
                }
            }
        }
        scanf("%s", ins);
        printf("%d\n", num_stickers(sx, sy, o));
        scanf("%d %d %d", &N, &M, &S);
    }
}

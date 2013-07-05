#include<stdio.h>
#include<string.h>

using namespace std;

char sky[101][101];

int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,-1,1,1,-1};

int R,C;

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<R&&y<C;
}

int main(){
    scanf("%d %d", &R, &C);
    while(!(R==0&C==0)){
        for (int i=0;i<R;i++)
            scanf("%s", sky[i]);
        int count = 0, flag;
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++){
                if (sky[i][j]!='*')
                    continue;
                flag = 1;
                for (int k=0;k<8;k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if (inside_grid(nx,ny)&&sky[nx][ny]=='*'){
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    count++;
            }
        printf("%d\n", count);
        scanf("%d %d", &R, &C);
    }
}

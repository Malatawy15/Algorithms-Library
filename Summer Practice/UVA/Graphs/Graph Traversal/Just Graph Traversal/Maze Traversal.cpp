#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define r(a) ((a+1)%4)
#define l(a) ((a+3)%4)

char maze[61][61];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main(){
    int t, r, c, x, y, f, nx, ny, flag;
    char str[1000];
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &r, &c);
        gets(str);
        for (int i=0;i<r;i++)
            gets(maze[i]);
        scanf("%d %d", &x, &y);
        x--;y--;
        f = 0;
        flag = 0;
        while(true){
            scanf("%s", str);
            for (int i=0;i<strlen(str);i++)
                if (str[i]=='L'){
                    f = l(f);
                }
                else if (str[i]=='R'){
                    f = r(f);
                }
                else if (str[i]=='F'){
                    nx = x+dx[f];
                    ny = y+dy[f];
                    if (nx>=0&&ny>=0&&nx<r&&ny<c)
                        if (maze[nx][ny]!='*'){
                            x = nx;
                            y = ny;
                        }
                }
                else if (str[i]=='Q'){
                    flag = 1;
                    break;
                }
            if (flag)
                break;
        }
        printf("%d %d %c\n", x+1, y+1, f==0?'N':f==1?'E':f==2?'S':'W');
        if (t)
            printf("\n");
    }
}

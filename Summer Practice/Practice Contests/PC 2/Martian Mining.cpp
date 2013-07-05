#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N,M;

int blog[502][502];
int blogdp[502][502];
int yeye[502][502];
int yeyedp[502][502];
int dir[502][502];
//int counted[502][502];

void dp(int x, int y){
    if (x==N-1&&y==M-1){
        if (blog[x][y]>yeye[x][y]){
            blogdp[x][y] = blog[x][y];
            yeyedp[x][y] = 0;
            dir[x][y] = 0;
        }
        else if (blog[x][y]==yeye[x][y]){
            blogdp[x][y] = blog[x][y];
            yeyedp[x][y] = yeye[x][y];
            dir[x][y] = 0;
        }
        else{
            blogdp[x][y] = 0;
            yeyedp[x][y] = yeye[x][y];
            dir[x][y] = 1;
        }
        return;
    }
    if (yeyedp[x][y]!=-1&&blogdp[x][y]!=-1)
        return;
    if (x==N-1){
        dp(x,y+1);
        if (blog[x][y]>yeye[x][y]+yeyedp[x][y+1]){
            blogdp[x][y] = blog[x][y];
            yeyedp[x][y] = 0;
            dir[x][y] = 0;
        }
        else if (blog[x][y]==yeye[x][y]+yeyedp[x][y+1]){
            blogdp[x][y] = blog[x][y];
            yeyedp[x][y] = yeye[x][y]+yeyedp[x][y+1];
            dir[x][y] = 0;
        }
        else{
            blogdp[x][y] = 0;
            yeyedp[x][y] = yeye[x][y]+yeyedp[x][y+1];
            dir[x][y] = 1;
        }
    }
    else if (y==M-1){
        dp(x+1,y);
        if (blog[x][y]+blogdp[x+1][y]>yeye[x][y]){
            blogdp[x][y] = blog[x][y]+blogdp[x+1][y];
            yeyedp[x][y] = 0;
            dir[x][y] = 0;
        }
        else if (blog[x][y]+blogdp[x+1][y]==yeye[x][y]){
            blogdp[x][y] = blog[x][y]+blogdp[x+1][y];
            yeyedp[x][y] = yeye[x][y];
            dir[x][y] = 0;
        }
        else{
            blogdp[x][y] = 0;
            yeyedp[x][y] = yeye[x][y];
            dir[x][y] = 1;
        }
    }
    else{
        dp(x+1,y);
        dp(x,y+1);
        if (blog[x][y]+blogdp[x+1][y]>yeye[x][y]+yeyedp[x][y+1]){
            blogdp[x][y] = blog[x][y]+blogdp[x+1][y];
            yeyedp[x][y] = 0;
            dir[x][y] = 0;
        }
        else if (blog[x][y]+blogdp[x+1][y]==yeye[x][y]+yeyedp[x][y+1]){
            blogdp[x][y] = blog[x][y]+blogdp[x+1][y];
            yeyedp[x][y] = yeye[x][y]+yeyedp[x][y+1];
            dir[x][y] = 1;
        }
        else{
            blogdp[x][y] = 0;
            yeyedp[x][y] = yeye[x][y]+yeyedp[x][y+1];
            dir[x][y] = 1;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    while(!(N==0&&M==0)){
        memset(blogdp, -1, sizeof blogdp);
        memset(yeyedp, -1, sizeof yeyedp);
        //memset(counted, 0, sizeof counted);
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                scanf("%d", &yeye[i][j]);
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                scanf("%d", &blog[i][j]);
        dp(0,0);
        /*for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                printf("%d ",dir[i][j]);
            }
            printf("\n");
        }*/
        int sum=0;
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                if (dir[i][j]){
                    for (int x = i+1;x<N;x++)
                        dir[x][j] = 1;
                }
                else{
                    for (int x = j+1;x<M;x++)
                        dir[i][x] = 0;
                }
        /*for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                printf("%d ",dir[i][j]);
            }
            printf("\n");
        }*/
        for (int i=0;i<N;i++)
            if (dir[i][0]){
                for (int j=0;j<M;j++){
                    if (dir[i][j])
                        sum+=yeye[i][j];
                    else break;
                }
            }
        for (int i=0;i<M;i++)
            if (!dir[0][i]){
                for (int j=0;j<N;j++){
                    if (!dir[j][i])
                        sum+=blog[j][i];
                    else break;
                }
            }
        printf("%d %d %d\n",sum, blogdp[0][0], yeyedp[0][0]);
        scanf("%d %d", &N, &M);
    }
}
/* Failing Case:
4 4
0 0 10 9
1 3 10 0
4 2 1 3
1 1 20 0
10 0 1 0
1 1 1 30
0 0 5 5
5 10 10 10
0 0
output: 98 while it should be 99
error in: direction when both directions give equal elements
*/

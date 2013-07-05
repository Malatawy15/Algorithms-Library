#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,1,-1};

int vis[50][50];
int ind, size;
char grid[100][100];

int dfs(int x, int y){
    if (x<0||y<0||x>=ind||y>=size)
        return 0;
    if (vis[x][y]||grid[x][y]=='0')
        return 0;
    vis[x][y] = 1;
    int count = 1;
    for (int i=0;i<8;i++)
        count+=dfs(x+dx[i], y+dy[i]);
    return count;
}

int main(){
    char c[100];
    int t;
    gets(c);
    sscanf(c, "%d", &t);
    gets(c);
    while(t--){
        memset(vis, 0, sizeof vis);
        for (int i=0;i<100;i++)
            for (int j=0;j<100;j++)
                grid[i][j] = '0';
        ind = 0;
        while(true){
            gets(grid[ind]);
            if (!strcmp(grid[ind],""))
                break;
            if (feof(stdin)){
                ind++;
                break;
            }
            ind++;
        }
        size = strlen(grid[0]);
        //printf("%d %d\n", ind, size);
        int max = 0,x;
        for (int i=0;i<ind;i++)
            for (int j=0;j<size;j++)
                if (grid[i][j]=='1'&&!vis[i][j]){
                    x = dfs(i,j);
                    if (max<x)
                        max = x;
                }
        printf("%d\n", max);
        if (t)
            printf("\n");
    }
}

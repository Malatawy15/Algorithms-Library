#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second

int N;
char grid[5][5];
int vis[5][5];

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<N&&y<N;
}

int* spread_virus(int* arr){
    int newv [5][5];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++){

        }
}

int main(){
    scanf("%d", &N);
    while(N>0){
        memset(vis, 0, sizeof vis);
        for (int i=0;i<N;i++)
            scanf("%s", grid[i]);
        int sx, sy;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                if (grid[i][j]=='#')
                    vis[i][j] = 2;
                else if (grid[i][j]=='@'){
                    sx = i;sy = j;
                }
        scanf("%d", &N);
    }
}

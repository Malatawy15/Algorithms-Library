#include <stdio.h>
#include <string.h>

using namespace std;

int R, C;

char grid [21][21];

int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

int check(){
    int tar, cnt, cfs = 0;
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++){
            if (grid[i][j]=='F'){
                cfs++;
                continue;
            }
            tar = grid[i][j]-'0';
            cnt = 0;
            for (int k=0;k<8;k++){
                int nx = i+dx[k], ny = j+dy[k];
                if (nx>=0&&ny>=0&&nx<R&&ny<C&&grid[nx][ny]=='F')
                    cnt++;
            }
            if (cnt!=tar)
                return 0;
        }
    return cfs==R*C?0:1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &R, &C);
        for (int i=0;i<R;i++)
            scanf("%s", grid[i]);
        if (check())
            printf("Well done Clark!\n");
        else printf("Please sweep the mine again!\n");
    }
}

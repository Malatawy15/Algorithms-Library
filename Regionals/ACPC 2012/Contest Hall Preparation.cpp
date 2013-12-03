#include<stdio.h>
#include<stdio.h>
#include<string.h>

using namespace std;

int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,1,-1};

int N, M;
int b[101][101];
int vis[10000];

int check(int x, int y){
    for (int k=0;k<8;k++){
        int nx = x+dx[k], ny=y+dy[k];
        if (nx>=0&&nx<N&&ny>=0&&ny<M){
            if (b[nx][ny]==b[x][y])
                return 1;
        }
    }
    return 0;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &M);
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                scanf("%d", &b[i][j]);
        memset(vis,0,sizeof vis);
        for (int i=0;i<N;i++)
        for (int j=0;j<M;j++){
            if (b[i][j]!=-1&&check(i,j))
                vis[b[i][j]] = 1;
        }
        int sum = 0;
        for (int i=0;i<1000;i++)
            sum+=vis[i];
        printf("%d\n", sum);
    }
}

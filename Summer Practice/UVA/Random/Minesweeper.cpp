#include<stdio.h>

using namespace std;

char grid [100][100];

int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,-1,1,-1};

int main(){
    int N, M, sum, field = 1;
    scanf("%d %d", &N, &M);
    while(!(M==0&&N==0)){
        if (field!=1)
            printf("\n");
        for (int i=0;i<N;i++)
            scanf("%s", grid[i]);
        printf("Field #%d:\n", field++);
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                sum = 0;
                if (grid[i][j]=='*'){
                    printf("*");
                    continue;
                }
                for (int k=0;k<8;k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if (nx>=0&&ny>=0&&nx<N&&ny<M&&grid[nx][ny]=='*')
                        sum++;
                }
                printf("%d", sum);
            }
            printf("\n");
        }
        scanf("%d %d", &N, &M);
    }
}

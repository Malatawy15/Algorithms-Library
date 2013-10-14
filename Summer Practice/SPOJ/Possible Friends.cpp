#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int M;
int mat[51][51];

int main(){
    char buf[51];
    int t;
    scanf("%d", &t);
    while(t--){
        //scanf("%d", &M);
        scanf("%s", buf);
        M = strlen(buf);
        //printf("M: %d\n", M);
        for (int j=0;j<M;j++)
            if (buf[j]=='Y')
                mat[0][j] = 1;
            else mat[0][j] = 0;
        for (int i=1;i<M;i++){
            scanf("%s", buf);
            for (int j=0;j<M;j++)
                if (buf[j]=='Y')
                    mat[i][j] = 1;
                else mat[i][j] = 0;
        }
        for (int k=0;k<M;k++)
            for (int i=0;i<M;i++)
                for (int j=0;j<M;j++)
                    if (i!=j&&!mat[i][j]&&mat[i][k]==1&&mat[k][j]==1)
                        mat[i][j] = 2;
        int maxi = -1, maxI, cur;
        for (int i=0;i<M;i++){
            cur = 0;
            for (int j=0;j<M;j++)
                if (mat[i][j]>1)
                    cur++;
            if (cur>maxi){
                maxi = cur;
                maxI = i;
            }
        }
        printf("%d %d\n", maxI, maxi);
    }
}

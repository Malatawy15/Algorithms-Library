#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int adj[1001][1001];
int N;

int main(){
    int cases = 1;
    scanf("%d",&N);
    while(N){
        int sum = 0,cut = 0, cur;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++){
                scanf("%d",&adj[i][j]);
                sum+=adj[i][j];
            }
        for (int i=0;i<N;i++){
            cur = 0;
            for (int j=0;j<N;j++){
                cur+=adj[i][j];
                cur-=adj[j][i];
            }
            if (cur>0)
                cut+=cur;
        }
        printf("%d. %d %d\n",cases++,sum,cut);
        scanf("%d",&N);
    }
}

#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>

using namespace std;

int N;
int mat[25][25];
int survive[25];
int vis[1048580];

void dp(int bitmask){
    if (vis[bitmask])
        return;
    vis[bitmask] = 1;
    int sur = 0, surI;
    for (int i=0;i<N;i++){
        if (bitmask&(1<<i)) continue;
        int sum = 0;
        for (int j=0;j<N;j++) if (!(bitmask&(1<<j))) sum+=mat[i][j];
        if (sum>0) dp(bitmask|(1<<i));
        else {
            sur++;
            surI = i;
        }
    }
    if (sur==1) survive[surI] = 1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                scanf("%d", &mat[i][j]);
        memset(vis,0,sizeof vis);
        memset(survive,0,sizeof survive);
        dp(0);
        int cnt = 0;
        for (int i=0;i<N;i++) cnt+=survive[i];
        if (cnt==0){
            printf("0\n");
        }
        else {
            int f = 0;
            for (int i=0;i<N;i++)
            if (survive[i]){
                if (f)
                    printf(" %d", i+1);
                else printf("%d", i+1), f = 1;
            }
            printf("\n");
        }
    }
}

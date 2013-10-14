#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
    int t, N;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        int dis[N][2];
        int len[N];
        for (int i=0;i<N;i++)
            scanf("%d", &len[i]);
        memset(dis,0,sizeof dis);
        int sum = 0;
        for (int i=0;i<N-1;i++){
            sum+=len[i];
            dis[i+1][0] = sum;
        }
        sum = 0;
        for (int i=N-1;i>0;i--){
            sum+=len[i];
            dis[i][1] = sum;
        }
        int mini = 2000000010;
        for (int i=0;i<N;i++){
            //i, N-i-1
            int f = i, t = (i+1)%N, d1 = dis[f][0], d2 = dis[t][1];
            mini = min(mini, (min(d1,d2)<<1)+max(d1,d2));
        }
        printf("%d\n", mini);
    }
}

#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N, CN;
char str[30];
int dp[33554434];
int vis[33554434];

int gen(int &i, int bitmask){
    int si = i++;
    if (bitmask&(1<<si))
        return bitmask;
    char c = str[si];
    for (;i<N;i++){
        if(bitmask&(1<<i))
            continue;
        else if (str[i]==c){
            bitmask|=(1<<si);
            bitmask|=(1<<i);
        }
        else break;
    }
    return bitmask;
}

int can(int bitmask){
    if (bitmask==(1<<N)-1)
        return 1;
    if (vis[bitmask]==CN)
        return dp[bitmask];
    vis[bitmask] = CN;
    for (int i=0;i<N;){
        int nb = gen(i,bitmask);
        if (nb!=bitmask)
        if (can(nb)){
            return dp[bitmask] = 1;
        }
    }
    return dp[bitmask] = 0;
}

int main(){
    int t;
    scanf("%d", &t);
    CN = 1;
    while(t--){
        scanf("%s", str);
        N = strlen(str);
        printf("%d\n", can(0));
        CN++;
    }
}

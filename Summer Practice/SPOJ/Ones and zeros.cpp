#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<queue>

using namespace std;


int pows[51];
long long pows2[64];
int vis[20000];

void comp(){
    pows2[0] = 1LL;
    for (int i=1;i<64;i++)
        pows2[i] = pows2[i-1]<<1;
}

void bfs(int N){
    if (N==1){
        printf("1\n");
        return;
    }
    vector<int> rem;
    vector<long long> nums;
    rem.push_back(0);
    nums.push_back(0LL);
    rem.push_back(1);
    nums.push_back(1LL);
    vis[1] = 1;
    int size, x;
    memset(vis,0,sizeof vis);
    pows[0] = 1;
    for (int i=1;i<51;i++){
        pows[i] = (10*pows[i-1])%N;
        size = rem.size();
        for (int j=0;j<size;j++){
            x = (rem[j]+pows[i])%N;
            if(x==0){
                x = nums[j]+pows2[i];
                int rrr = 1<<31-__builtin_clz(x);
                while (rrr>0){
                    printf("%d",(x&rrr)>0);
                    rrr>>=1;
                }
                printf("\n");
                return;
            }
            if (vis[x])
                continue;
            vis[x] = 1;
            rem.push_back(x);
            nums.push_back(nums[j]+pows2[i]);
        }
    }
}

int main(){
    comp();
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bfs(n);
    }
}

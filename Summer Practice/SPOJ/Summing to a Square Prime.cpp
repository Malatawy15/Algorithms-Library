#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nums;
int prime[10001];
int dp[7994][4];

void sieve(){
    memset(prime,0,sizeof prime);
    prime[0] = 1;
    prime [1] = 1;
    for (int i =2;i*i<=10000;i++){
        if (!prime[i]){
            for (int j = i*i;j<10001;j+=i){
                prime [j] = 1;
            }
        }
    }
}

void add(){
    int no = 1, ne = 2, nn;
    //nums.push_back(2);
    for (int i=1;i<91;i++)
    for (int j=i;j<91;j++){
        nn = i*i+j*j;
        if (nn<10000){
            if (!prime[nn])
                nums.push_back(nn);
        }
    }
    sort(nums.begin(), nums.end());
}

int calc(int num, int k){
    if (k<=0)
        return 0;
    //printf("%d %d\n", num, k);
    if (num==0||num==1)
        return 1;
    if (num<0)
        return 0;
    if (dp[num][k]!=-1)
        return dp[num][k];
    //dp[num][k] = 0;
    dp[num][k] = calc(num-k, k)+calc(num, k-1);
    //printf("%d %d: %d\n", num, k, dp[num][k]);
    return dp[num][k];
}

int main(){
    sieve();
    add();
    int t, n, p;
    memset(dp, -1, sizeof dp);
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &p);
        printf("%d\n", calc(nums[n-1], p));
    }
}

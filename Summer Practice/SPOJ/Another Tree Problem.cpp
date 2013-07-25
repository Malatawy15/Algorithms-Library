#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>

using namespace std;

#define Edge pair<int, int>
#define id first
#define cost second
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define mod(a,b) ((a)%b)

int N;
vector<Edge> graph[100010];
long long dp[100010][2];
int pre[100010];

int dfs(){
    stack<int> st;
    st.push(1);
    int  pc = 0;
    long long sum = 0LL;
    pre[1] = pc++;
    while(!st.empty()){
        int n = st.top(), f = 0, n1, s = 0;
        //printf("Call: %d\n", n);
        st.pop();
        dp[n][0] = 0LL;
        dp[n][1] = 0LL;
        for (int i=0;i<graph[n].size();i++){
            n1 = graph[n][i].id;
            if (dp[n1][0]==-1){
                if (!f){
                    f = 1;
                    st.push(n);
                }
                st.push(n1);
                pre[n1] = pc++;
            }
        }
        if (f)
            continue;
        for (int i=0;i<graph[n].size();i++){
            n1 = graph[n][i].id;
            if (pre[n1]>pre[n])
                dp[n][0] = ((dp[n][0]%MOD)+((graph[n][i].cost*((dp[n1][0]+1)%MOD))%MOD))%MOD;
        }
        sum = (sum%MOD+dp[n][0]%MOD)%MOD;
        //printf("SUM1: %d\n",sum);
        //if (graph[n].size()<=1)
            //continue;
        long long tmp = dp[n][0]%MOD, tmp1 = 0LL;
        for (int i=0;i<graph[n].size()-1;i++){
            n1 = graph[n][i].id;
            if (pre[n]>=pre[n1])
                continue;
            tmp1 = ((graph[n][i].cost*((dp[n1][0]+1)%MOD))%MOD);
            tmp = ((tmp%MOD-tmp1%MOD)+MOD)%MOD;
      //      printf("N1: %d %d %d\n",n1,tmp,tmp1);
            sum = (sum%MOD+((tmp*tmp1)%MOD))%MOD;
        }
       // printf("SUM2: %d\n",sum);
    }
    //for (int i=1;i<=N;i++)
        //printf("%d ",pre[i]);
    //printf("\n");
    return sum;
}

int main(){
    int x,y,z;
    scanf("%d",&N);
    for (int i=1;i<N;i++){
        scanf("%d %d %d",&x,&y,&z);
        graph[x].push_back(mp(y,z));
        graph[y].push_back(mp(x,z));
    }
    memset(dp,-1,sizeof dp);
    memset(pre,-1,sizeof pre);
    printf("%d\n", dfs());
}

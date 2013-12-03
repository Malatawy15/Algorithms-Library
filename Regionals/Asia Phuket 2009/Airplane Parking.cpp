#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>

using namespace std;

int N;
int vals[305][2];
set<int> times;
set<int>::iterator it;

int dp[605][605];
int counts[605][605];


int maximize(int s, int e){
    if (s==e)
        return counts[s][e];
    if (dp[s][e]!=-1)
        return dp[s][e];
    dp[s][e] = 0;
    for (int i=s;i<=e;i++)
        dp[s][e] = max(dp[s][e],maximize(s,i)+maximize(i,e));
    return dp[s][e] = dp[s][e] + counts[s][e];
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        times.clear();
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%d %d", &vals[i][0], &vals[i][1]);
            times.insert(vals[i][0]);
            times.insert(vals[i][1]);
        }
        memset(dp,-1,sizeof dp);
        memset(counts,0,sizeof counts);
        for (int i=0;i<N;i++){
            int a = -1, b = -1;
            for (int j =0;j<times.size();j++){
                if (a!=-1&&b!=-1)
                    break;
                it = times.begin();
                advance(it,j);
                if (*(it)==vals[i][0])
                    a = j;
                if (*(it)==vals[i][1])
                    b = j;
            }
            counts[a][b]++;
        }
        printf("%d\n", maximize(0,times.size()-1));
    }
}

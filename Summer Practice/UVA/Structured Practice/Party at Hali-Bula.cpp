#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int N;
vector<int> graph[201];
int dp[201][2][2];

map<string, int> nti;
map<string, int>::iterator it;

int recur(int n, int can){
    if (dp[n][can][0]!=-1)
        return dp[n][can][0];
    dp[n][can][0] = 0;
    dp[n][can][1] = 0;
    if (graph[n].size()==0)
        return dp[n][can][0] = can;
    int s1 = 0, s2 = 1, u1 = 0, u2 = 0;
    for (int i=0;i<graph[n].size();i++){
        s1 += recur(graph[n][i],1);
        u1 |= dp[graph[n][i]][1][1];
        if (can){
            s2 += recur(graph[n][i],0);
            u2 |= dp[graph[n][i]][0][1];
        }
    }
    if (!can){
        dp[n][can][1] = u1;
        return dp[n][can][0] = s1;
    }
    else {
        if (s1==s2){
            dp[n][can][1] = 1;
            return dp[n][can][0] = s1;
        }
        else if (s1>s2){
            dp[n][can][1] = u1;
            return dp[n][can][0] = s1;
        }
        else{
            dp[n][can][1] = u2;
            return dp[n][can][0] = s2;
        }

    }
}

int main(){
    cin>>N;
    string s1, s2;
    int i1, i2;
    while(N){
        nti.clear();
        for (int i=0;i<N;i++)
            graph[i].clear();
        int ind = 0;
        cin>>s1;
        nti.insert(make_pair(s1,ind++));
        for (int i=0;i<N-1;i++){
            cin>>s1>>s2;
            it = nti.find(s1);
            if (it==nti.end()){
                i1 = ind;
                nti.insert(make_pair(s1,ind++));
            }
            else i1 = it->second;
            it = nti.find(s2);
            if (it==nti.end()){
                i2 = ind;
                nti.insert(make_pair(s2,ind++));
            }
            else i2 = it->second;
            graph[i2].push_back(i1);
        }
        memset(dp,-1,sizeof dp);
        int ans = recur(0,1);
        printf("%d %s\n",ans,dp[0][1][1]?"No":"Yes");
        cin>>N;
    }
}

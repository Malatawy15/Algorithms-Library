#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int IMP = 3;
const int INS = 2;
const int STD = 1;
const int NOT = 0;

int N;
vector<string> dep[10001];
vector<int> graph[10001];

int vis[10001];

int dfs(int node){
    if (vis[node]==INS)
        return 1;
    if (vis[node]==STD){
        vis[node] = IMP;
        return 0;
    }
    if (vis[node]==IMP)
        return 0;
    vis[node] = STD;
    for (int i=0;i<graph[node].size();i++){
        if (!dfs(graph[node][i])){
            vis[node] = IMP;
            return 0;
        }
    }
    vis[node] = INS;
    return 1;
}

int count(){
    int sum = 0;
    for (int i=0;i<N;i++)
        if (dfs(i))
            sum++;
    return sum;
}

int main(){
    map<string, int> mp;
    map<string, int>::iterator it;
    string s;
    N = 0;
    while(cin>>s){
        mp[s] = N;
        cin>>s;
        while(strcmp(s.c_str(),"0")!=0){
            dep[N].push_back(s);
            cin>>s;
        }
        N++;
    }
    memset(vis,NOT,sizeof vis);
    for (int i=0;i<N;i++){
        for (int j=0;j<dep[i].size();j++){
            it = mp.find(dep[i][j]);
            if (it==mp.end()){
                vis[i] = IMP;
                break;
            }
            else graph[i].push_back(it->second);
        }
    }
    printf("%d\n", count());
}

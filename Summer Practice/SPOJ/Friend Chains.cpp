#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

#define pi pair<int, int>

int N, M;
vector<int> graph[1001];
map<string, int> mp;

char buf[1000];
int vis[1001];

int counter;

int bfs(int node){
    queue<pi> q;
    memset(vis,0,sizeof vis);
    q.push(pi(node,0));
    int maxi = -1;
    vis[node] = 1;
    while(!q.empty()){
        pi p = q.front();
        q.pop();
        vis[p.first] = 1;
        counter++;
        maxi = max(maxi,p.second);
        for (int i=0;i<graph[p.first].size();i++){
            if (!vis[graph[p.first][i]]){
                vis[graph[p.first][i]] = 1;
                q.push(pi(graph[p.first][i],p.second+1));
            }
        }
    }
    return maxi;
}

int calc(){
    int maxi = -1, res;
    for (int i=0;i<N;i++){
        counter = 0;
        res = bfs(i);
        if (counter!=N)
            return -1;
        maxi = max(maxi,res);
    }
    return maxi;
}

int main(){
    scanf("%d", &N);
    while(N){
        for (int i=0;i<N;i++)
            graph[i].clear();
        mp.clear();
        for (int i=0;i<N;i++){
            scanf("%s", buf);
            mp.insert(make_pair(string(buf),i));
        }
        scanf("%d", &M);
        int a,b;
        for (int i=0;i<M;i++){
            scanf("%s", buf);
            a = mp.find(string(buf)) -> second;
            scanf("%s", buf);
            b = mp.find(string(buf)) -> second;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        printf("%d\n", calc());
        scanf("%d", &N);
    }
}

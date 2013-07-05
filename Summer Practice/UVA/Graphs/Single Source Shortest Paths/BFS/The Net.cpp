#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

#define Node pair<int, int>
#define id first
#define cost second

vector<int> graph[310];
vector<int> path;

int vis[310];
int N;

void reconstruct(int s, int d){
    if (s==d)
        path.push_back(s);
    else {
        reconstruct(s, vis[d]);
        path.push_back(d);
    }
}

int bfs(int s, int d){
    queue<int> q;
    q.push(s);
    memset(vis, -1, sizeof vis);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if (n==d){
            path.clear();
            reconstruct(s,d);
            return 1;
        }
        for (int i=0;i<graph[n].size();i++){
            if (vis[graph[n][i]]==-1){
                vis[graph[n][i]] = n;
                q.push(graph[n][i]);
            }
        }
    }
    return -1;
}

int main(){
    int s, d, m;
    while(scanf("%d", &N)>0){
        printf("-----\n");
        for (int i=1;i<=N;i++){
            char buf[1000];
            scanf("%s", buf);
            char * pch;
            pch = strtok (buf,"-,");
            sscanf(pch, "%d", &s);
            while (pch != NULL){
                sscanf(pch, "%d", &d);
                graph[s].push_back(d);
                pch = strtok (NULL, " ,.-");
            }
        }
        scanf("%d", &m);
        //printf("M: %d\n", m);
        while(m--){
            scanf("%d %d",&s,&d);
          //  printf("BFS: %d %d\n", s, d);
            int ans = bfs(s,d);
            if (ans==-1)
                printf("connection impossible\n");
            else{
                for (int i=0;i<path.size()-1;i++)
                     printf("%d ", path[i]);
                printf("%d\n", path[path.size()-1]);
            }
        }
        for (int i=0;i<310;i++){
            graph[i].clear();
        }
    }
}

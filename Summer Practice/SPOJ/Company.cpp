#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int level[1010];
vector<int> graph[1010];

void dfs(int node, int lev){
    if (level[node]>=2)
        return;
    level[node] = lev;
    for (int i=0;i<graph[node].size();i++)
        dfs(graph[node][i],lev+1);
}

int main(){
    int N,M,x,y;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
    }
    vector<pair<int,int> > vec;
    int sum = 0;
    for (int i=1;i<=N;i++){
        memset(level, 0, sizeof level);
        dfs(i,0);
        for (int j=0;j<graph[i].size();j++)
            if (level[graph[i][j]]<2){
                sum++;
                vec.push_back(make_pair(i,graph[i][j]));
            }
    }
    printf("%d\n", sum);
    for (int i=0;i<vec.size();i++)
        printf("%d %d\n",vec[i].first,vec[i].second);
}

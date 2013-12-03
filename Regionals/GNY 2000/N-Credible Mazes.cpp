#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>

using namespace std;

typedef vector<int> vi;

int N, n;
vi vis;
map<vi, int> mp;
map<vi, int>::iterator it;

vector<vi> graph;

int dfs(int node){
    if (node==1)
        return 1;
    if (vis[node])
        return 0;
    vis[node] = 1;
    for (int i=0;i<graph[node].size();i++)
        if (dfs(graph[node][i]))
            return 1;
    return 0;
}

int main(){
    scanf("%d", &n);
    int a, cn = 1, ind1, ind2;
    vi inp;
    while(n){
        N = 0;
        graph.clear();
        vis.clear();
        mp.clear();
        inp.clear();
        for (int i=0;i<n;i++){
            scanf("%d", &a);
            inp.push_back(a);
        }
        mp.insert(make_pair(inp,N++));
        graph.push_back(vi());
        inp.clear();
        for (int i=0;i<n;i++){
            scanf("%d", &a);
            inp.push_back(a);
        }
        mp.insert(make_pair(inp,N++));
        graph.push_back(vi());
        while(1){
            inp.clear();
            int f = 0;
            for (int i=0;i<n;i++){
                scanf("%d", &a);
                if (a==-1){
                    f = 1;
                    break;
                }
                inp.push_back(a);
            }
            if (f) break;
            it = mp.find(inp);
            if (it==mp.end()){
                ind1 = N++;
                graph.push_back(vi());
                mp.insert(make_pair(inp,ind1));
            }
            else ind1 = it -> second;
            inp.clear();
            for (int i=0;i<n;i++){
                scanf("%d", &a);
                if (a==-1)
                    break;
                inp.push_back(a);
            }
            it = mp.find(inp);
            if (it==mp.end()){
                ind2 = N++;
                graph.push_back(vi());
                mp.insert(make_pair(inp,ind2));
            }
            else ind2 = it -> second;
            graph[ind1].push_back(ind2);
            //printf("INDEX: %d %d\n", ind1, ind2);
            graph[ind2].push_back(ind1);
        }
        vis = vi(N,0);
        if (dfs(0)){
            printf("Maze #%d can be travelled\n",cn++);
        }
        else {
            printf("Maze #%d cannot be travelled\n",cn++);
        }
        scanf("%d", &n);
    }
}

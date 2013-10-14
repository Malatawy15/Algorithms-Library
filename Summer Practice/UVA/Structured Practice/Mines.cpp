#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int N;
int vals[2002][3];
vector<int>graph[2002];
stack<int> st;
int vis[2002];

void dfs(int node, int is){
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i=0;i<graph[node].size();i++)
        dfs(graph[node][i], is);
    if (is)
        st.push(node);
}

void build_graph(){
    for(int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i!=j&&abs(vals[i][0]-vals[j][0])<=(vals[i][2]>>1)&&abs(vals[i][1]-vals[j][1])<=(vals[i][2]>>1))
                graph[i].push_back(j);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for (int i=0;i<N;i++)
            scanf("%d %d %d",&vals[i][0],&vals[i][1],&vals[i][2]);
        for (int i=0;i<N;i++)
            graph[i].clear();
        build_graph();
        memset(vis,0,sizeof vis);
        for (int i=0;i<N;i++)
            if (!vis[i])
                dfs(i, 1);
        int sum = 0, nn;
        memset(vis,0,sizeof vis);
        for (int i=0;i<N;i++){
            nn = st.top();
            st.pop();
            if (!vis[nn])
                sum++, dfs(nn, 0);
        }
        printf("%d\n", sum);
    }
}

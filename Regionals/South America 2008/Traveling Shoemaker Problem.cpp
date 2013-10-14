#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, C;

vector<int> conf[101];
int ntc[501][3];
int vis[501];
int tot;

int other(int nd, int t){
    if (ntc[nd][0]==1)
        return t;
    else if (t==ntc[nd][1])
        return ntc[nd][2];
    else return ntc[nd][1];
}

int dfs(int node, int ticket){
    tot++;
    vis[node] = 1;
    if (tot==N)
        return 1;
    int nt;
    if (ntc[node][0]==1){
        nt = ticket;
    }
    else if (ntc[node][1]==ticket)
        nt = ntc[node][2];
    else nt = ntc[node][1];
    int ccc[101];
    memset(ccc,0,sizeof ccc);
    for (int i=0;i<conf[nt].size();i++)
        if (conf[nt][i]!=node&&!vis[conf[nt][i]]&&!ccc[other(conf[nt][i],nt)])
            if (dfs(conf[nt][i],nt))
                return 1;
            else ccc[other(conf[nt][i],nt)] = 1;
    tot--;
    vis[node] = 0;
    return 0;
}

int find_node(){
    memset(vis,0,sizeof vis);
    tot = 0;
    for (int i=0;i<N;i++){
        if (dfs(i,ntc[i][1]))
            return i;
        if (ntc[i][0]==2&&dfs(i,ntc[i][2]))
            return i;
    }
    return -1;
}

int main(){
    int r,k;
    scanf("%d %d", &N, &C);
    while(!(!N&&!C)){
        memset(ntc,0,sizeof ntc);
        for (int i=1;i<=C;i++){
            conf[i].clear();
            scanf("%d", &k);
            for (int j=0;j<k;j++){
                scanf("%d", &r);
                if (ntc[r][0]==0)
                    ntc[r][1] = i;
                else ntc[r][2] = i;
                ntc[r][0]++;
                conf[i].push_back(r);
            }
        }
        printf("%d\n",find_node());
        scanf("%d %d", &N, &C);
    }
}

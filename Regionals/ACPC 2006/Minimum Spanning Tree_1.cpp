#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define Pair pair<int, pair<int, int> >
#define cst first
#define en1 second.first
#define en2 second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

int N, Q;
char inp[300000];
char tree[30000000];
int vis[1005];
int mat [1003][1003];

vector<Pair> graph[1005];

void reset_graph(){
    for (int i=0;i<1005;i++)
        graph[i].clear();
}

int prims(){
    reset_graph();
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    for (int i=1;i<=N;i++){
        for (int j=i+1;j<=N;j++){
            if (mat[i][j]!=0){
                graph[i].push_back(mp(mat[i][j],j,0));
                graph[j].push_back(mp(mat[i][j],i,0));
            }
        }
    }
    memset(vis,0,sizeof vis);
    pq.push(mp(0,1,1));
    int sum = 0;
    while(!pq.empty()){
        Pair pp = pq.top();
        pq.pop();
        if (vis[pp.en1])
            continue;
        sum+=pp.cst;
        //printf("PQ: %d %d %d\n",pp.en2,pp.cst,pp.en1);
        vis[pp.en1] = 1;
        for (int i=0;i<graph[pp.en1].size();i++){
            pq.push(graph[pp.en1][i]);
        }
    }
    return sum;
}


void eat_spaces(int &ind){
    while(tree[ind]==' ')
        ind++;
}

int parse_tree(int &ind){
    eat_spaces(ind);
    if (tree[ind]=='(')
        ind++;
    else{
        int root = 0;
        while(tree[ind]>='0'&&tree[ind]<='9'){
            root = root*10 + (tree[ind]-'0');
            ind++;
        }
        return root;
    }
    eat_spaces(ind);
    int root = 0;
    while(tree[ind]>='0'&&tree[ind]<='9'){
        root = root*10 + (tree[ind]-'0');
        ind++;
    }
    eat_spaces(ind);
    while(tree[ind]!=')'){
        int rr = parse_tree(ind);
        if (mat[root][rr]!=0)
            graph[root].push_back(mp(mat[root][rr],rr,0));
        eat_spaces(ind);
    }
    ind++;
    //printf("RET: %d %d %d\n",ind,root,sum);
    return root;
}

int cf;

pair<int, int> dfs(int node){
    if (vis[node]){
        cf = 1;
        return make_pair(0,0);
    }
    vis[node] = 1;
    pair<int,int> pp(0,1);
    for (int i=0;i<graph[node].size();i++){
        pair<int, int> pp1 = dfs(graph[node][i].en1);
        pp.first+=graph[node][i].cst;
        pp.first+=pp1.first;
        pp.second+=pp1.second;
    }
    return pp;
}

int main(){
    int cn = 1;
    gets(inp);
    sscanf(inp,"%d", &N);
    while(N){
        int in;
        memset(mat,0,sizeof mat);
        for (int i=1;i<N;i++){
            mat[i][i] = 0;
            gets(inp);
            int jj = 0, ss = strlen(inp);
            for (int j=i+1;j<=N;j++){
                while(inp[jj]==' ')
                    jj++;
                in = 0;
                while(jj<ss&&(inp[jj]>='0'&&inp[jj]<='9')){
                    in = in*10 + (inp[jj]-'0');
                    jj++;
                }
                mat[i][j] = in;
                mat[j][i] = in;
            }
        }
        int mst = prims(), indi = 0;
        //printf("MST: %d\n", mst);
        gets(inp);
        sscanf(inp,"%d", &Q);
        for (int i=1;i<=Q;i++){
            gets(tree);
            if (mst==0){
                printf("%d.%d NO\n",cn,i);
                continue;
            }
            indi = 0;
            reset_graph();
            cf = 0;
            int root = parse_tree(indi);
            memset(vis,0,sizeof vis);
            pair<int, int> pp = dfs(root);
            //printf("STAT: %d %d %d\n", cf,pp.first,pp.second);
            if (!cf&&pp.first==mst&&pp.second==N){
                printf("%d.%d YES\n",cn,i);
            }
            else printf("%d.%d NO\n",cn,i);
        }
        cn++;
        gets(inp);
        sscanf(inp,"%d", &N);
    }
}

/*
for (int i=1;i<=N;i++){
    for (int j=1;j<=N;j++)
        printf("%d ", mat[i][j]);
    printf("\n");
}
printf("MST: %d\n",mst);

4
4 2 1
4 0
3
5
(2 4 1)
(0000000000000000006 (  0000000003 ( 00000001 000000002) )  (0000000004 05) )
*/

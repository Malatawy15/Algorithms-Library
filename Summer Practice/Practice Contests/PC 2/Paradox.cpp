#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define Stat pair<int, int>
#define id first
#define asum second
#define EXP 1000000000

Stat graph[101];

int pos[101];
int assumed[101];

int N, current;

int dfs(int node, int tf){
    if (pos[node]==EXP)
        return 0;
    if (pos[node]!=-1)
        return tf != assumed[node];
    pos[node] = current++;
    assumed[node] = tf;
    if(dfs(graph[node].id, !(tf^graph[node].asum)))
        return 1;
    pos[node] = EXP;
    current--;
    return 0;
}

int find_paradox(){
    memset(pos,-1,sizeof pos);
    memset(assumed,-1,sizeof assumed);
    current = 0;
    for (int i=1;i<=N;i++){
        if (pos[i]!=EXP)
            if (dfs(i,1))
                return 1;
    }
    return 0;
}

int main(){
    scanf("%d",&N);
    int x;
    char state[100];
    while(N){
        for (int i=1;i<=N;i++){
            scanf("%d %s",&x,state);
            if (!strcmp(state,"true"))
                graph[i] = Stat(x,1);
            else
                graph[i] = Stat(x,0);
        }
        if (find_paradox())
            printf("PARADOX\n");
        else printf("NOT PARADOX\n");
        scanf("%d",&N);
    }
}

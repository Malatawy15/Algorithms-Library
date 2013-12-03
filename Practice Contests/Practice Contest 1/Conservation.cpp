#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N, M;
int lab[100001];
vector<int> graph[100001];
int depend[100001];
int vis[100001];

vector<int> init1, init2, cur1, cur2;


int counter(int turn){
    memset(vis,0,sizeof vis);
    if (!turn)
        cur1 = vector<int> (init1);
    else cur2 = vector<int> (init2);
    int num = 0, lps = 0;
    while(num<N){
        lps++;
        if (!turn){
            if (cur1.empty())
                return 1000000000;
            cur2.clear();
            for (int i=0;i<cur1.size();i++) vis[cur1[i]] = 1, num++;
            for (int i=0;i<cur1.size();i++){
                //printf("PROCESS %d: %d %d\n", lps,num,cur1[i]);
                for (int j=0;j<graph[cur1[i]].size();j++){
                    int v = graph[cur1[i]][j];
                    depend[v]--;
                    if (!vis[v]&&depend[v]<=0){
                        if (lab[v]==1){
                            cur1.push_back(v);
                            vis[v] = 1;
                            num++;
                        }
                        else cur2.push_back(v);
                    }
                }
            }
        }
        else {
            if (cur2.empty())
                return 1000000000;
            cur1.clear();
            for (int i=0;i<cur2.size();i++) vis[cur2[i]] = 1, num++;
            for (int i=0;i<cur2.size();i++){
                for (int j=0;j<graph[cur2[i]].size();j++){
                    int v = graph[cur2[i]][j];
                    depend[v]--;
                    if (!vis[v]&&depend[v]<=0){
                        if (lab[v]==2){
                            cur2.push_back(v);
                            vis[v] = 1;
                            num++;
                        }
                        else cur1.push_back(v);
                    }
                }
            }
        }
    }
    return lps;
}

int main(){
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        memset(depend,0,sizeof depend);
        scanf("%d %d", &N, &M);
        for (int i=0;i<N;i++){
            scanf("%d", &lab[i]);
            graph[i].clear();
        }
        for (int i=0;i<M;i++){
            scanf("%d %d", &a, &b);a--;b--;
            depend[b]++;
            graph[a].push_back(b);
        }
        for (int i=0;i<N;i++){
            if (depend[i]==0){
                if (lab[i]==1)
                    init1.push_back(i);
                else init2.push_back(i);
            }
        }
        printf("%d\n", min(counter(0), counter(1)));
    }
}

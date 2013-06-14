#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define Stop pair<int, int>
#define id first
#define cost second
#define EPS 1e-9

vector<int> stations [10010];
int imp[10010];
int imp1[10010];

double bfs(int s, int num){
    queue<Stop> q;
    int vis[10010];
    memset(vis, 0, sizeof vis);
    int stops = 0;
    q.push(Stop(s, 0));
    int times = 0;
    while (!q.empty()){
        Stop st = q.front();
        q.pop();
        if (vis[st.id])
            continue;
        if (imp[st.id]){
            times+=st.cost;
            if (++stops==num)
                break;
        }
        vis[st.id] = 1;
        for (int i=0;i<stations[st.id].size();i++)
            q.push(Stop(stations[st.id][i], st.cost+1));
    }
    return (times*1.0)/num;
}

int find_krochanska(vector<int> st){
    int station;
    double min = 1000000000, num;
    for (int i=0;i<st.size();i++){
        num = bfs(st[i], st.size())+EPS;
        //printf("Important: %d %lf\n",st[i]+1, num);
        if (num<min){
            station = st[i];
            min = num;
        }
        else if (num==min)
            if (st[i]<station)
                station = st[i];
    }
    return station;
}

int main(){
    int t,N,S,n,p;
    scanf("%d", &t);
    while(t--){
        vector<int>impv;
        scanf("%d %d", &N, &S);
        memset(imp, 0, sizeof imp);
        memset(imp1, 0, sizeof imp1);
        for (int i=0;i<N;i++)
            stations[i].clear();
        for (int i=1;i<=S;i++){
            scanf("%d",&p);
            scanf("%d",&n);
            while(n!=0){
                stations[p-1].push_back(n-1);
                stations[n-1].push_back(p-1);
                if (!imp1[p-1])
                    imp1[p-1] = i;
                else if (!imp[p-1]&&imp1[p-1]!=i){
                    imp[p-1] = 1;
                    impv.push_back(p-1);
                }
                if (!imp1[n-1])
                    imp1[n-1] = i;
                else if (!imp[n-1]&&imp1[n-1]!=i){
                    imp[n-1] = 1;
                    impv.push_back(n-1);
                }
                p = n;
                scanf("%d", &n);
            }
        }
        printf("Krochanska is in: %d\n", find_krochanska(impv)+1);
    }
}

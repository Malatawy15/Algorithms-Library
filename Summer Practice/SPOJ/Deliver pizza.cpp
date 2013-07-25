#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define Way pair<int, int>
#define cost first
#define id second

vector<Way> graph[3000];
int dis[3000];
vector<int> deliveries;
vector<int> times;
char grid[52][52];
int N, ND;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int minimize(int n, int bitmask){
    if (n==ND){
        int maxI = -1, maxJ = -1, totI = 0, totJ = 0;
        for (int i=0;i<ND;i++)
            if (bitmask&(1<<i)){
                totI+=(times[i]*2);
                maxI = i;
            }
            else {
                totJ+=(times[i]*2);
                maxJ = i;
            }
        if (maxI!=-1)
            totI-=times[maxI];
        if (maxJ!=-1)
            totJ-=times[maxJ];
        return max(totI, totJ);
    }
    return min(minimize(n+1,bitmask|(1<<n)),minimize(n+1,bitmask));
}

void dijkstra(int s){
    priority_queue<Way, vector<Way>, greater<Way> > pq;
    pq.push(make_pair(0,s));
    memset(dis,-1,sizeof dis);
    while(!pq.empty()){
        Way w = pq.top();
        pq.pop();
        if (dis[w.id]!=-1)
            continue;
        dis[w.id] = w.cost;
        for (int i=0;i<graph[w.id].size();i++){
            Way w1 = graph[w.id][i];
            pq.push(make_pair(w.cost+w1.cost, w1.id));
        }
    }
}

int compute(int si){
    for (int i=0;i<deliveries.size();i++)
        if (dis[deliveries[i]]!=-1){
            times.push_back(dis[deliveries[i]]);
        }
        else return -1;
    sort(times.begin(), times.end());
    return minimize(0,0);
}

int main(){
    int t,R,C;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&R,&C);
        for (int i=0;i<R;i++)
            scanf("%s",grid[i]);
        int ind = 0, si;
        N = R*C;
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++){
                if (grid[i][j]=='$')
                    deliveries.push_back(ind);
                if (grid[i][j]=='X')
                    si = ind;
                for (int k=0;k<4;k++){
                    int nx = i+dx[k], ny = j+dy[k], ind1 = ind+dy[k]+dx[k]*C;
                    if (nx<0||ny<0||nx>=R||ny>=C)
                        continue;
                    if (grid[i][j]=='$'||grid[i][j]=='X'){
                        if (grid[nx][ny]=='$'||grid[nx][ny]=='X')
                            graph[ind].push_back(make_pair(2,ind1));
                        else graph[ind].push_back(make_pair(2,ind1));
                    }
                    else {
                        if (grid[nx][ny]=='$'||grid[nx][ny]=='X')
                            graph[ind].push_back(make_pair(2,ind1));
                        else if (abs((grid[i][j]-'0')-(grid[nx][ny]-'0'))==0)
                            graph[ind].push_back(make_pair(1,ind1));
                        else if (abs((grid[i][j]-'0')-(grid[nx][ny]-'0'))==1)
                            graph[ind].push_back(make_pair(3,ind1));
                    }
                }
                ind++;
            }
        ND = deliveries.size();
        if (deliveries.size()==0||si==-1){
            times.clear();
            deliveries.clear();
            for (int i=0;i<N;i++)
                graph[i].clear();
            printf("0\n");
        }
        dijkstra(si);
        printf("%d\n",compute(si));
        times.clear();
        deliveries.clear();
        for (int i=0;i<N;i++)
            graph[i].clear();
    }
}


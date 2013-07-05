#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<math.h>

using namespace std;

#define Spark pair<double, int>
#define cost first
#define id second
#define EPS 1e-9

int pos[101][3];
vector<int>ins[101];
int vis[101];
double times[101];
int N;


double ptp_dis(int n1, int n2){
    int x1=pos[n1][0],x2=pos[n2][0],y1=pos[n1][1],y2=pos[n2][1];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


void dijkstra(){
    memset(vis,0,sizeof vis);
    int count = 0;
    priority_queue<Spark, vector<Spark>, greater<Spark> > pq;
    pq.push(Spark(0,1));
    while(!pq.empty()){
        Spark s = pq.top();
        pq.pop();
        if (vis[s.id])
            continue;
        vis[s.id] = 1;
        times[s.id] = s.cost;
        count++;
        if (count==N)
            return;
        for (int i=0;i<pos[s.id][2]&&i<ins[s.id].size();i++){
            if(!vis[ins[s.id][i]])
                pq.push(Spark(s.cost+ptp_dis(s.id,ins[s.id][i]),ins[s.id][i]));
            else pos[s.id][2]++;
        }
    }
}

int main(){
    int x,y,z;
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%d %d %d", &x, &y, &z);
        pos[i][0] = x;
        pos[i][1] = y;
        pos[i][2] = z;
        for (int j=0;j<N-1;j++){
            scanf("%d",&x);
            ins[i].push_back(x);
        }
    }
    dijkstra();
    for (int i=1;i<=N;i++)
        printf("%.6lf\n", times[i]);
}

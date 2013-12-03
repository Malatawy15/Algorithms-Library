#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define Train pair<double, pair<double, int> >
#define exp first
#define stt second.first
#define id second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

map<string, int> nti;
map<string, int>::iterator it;

int N, cities;

vector<Train>graph[2001];

double expected(int t, int p, int d){
    double r1 = t * 1.0 * (100-p) / 100;
    double r2 = t * d + ((d * (d+1))>>1);
    r2 = r2 * 1.0 * p / d / 100;
    return r1 + r2;
}

double wait_time(double d, int st){
    //printf("WTC\n");
    if (st<d) return 60-d+st;
    else if (d<st) return st - d;
    else return 0;
}

double next_start(double st, double d){
    /*double nd = st + d;
    int n = nd / 60;
    n *= 60;*/
    //printf("NSC\n");
    d+=st;
    int x = d;
    double nd = d - x;
    x%=60;
    d = x + nd;
    return d;
}

int vis[1001];

double dijkstra (){
    printf("Dijkstra Called\n");
    priority_queue<Train, vector<Train>, greater<Train> > pq;
    memset(vis, 0, sizeof vis);
    for (int i=0;i<graph[0].size();i++){
        Train t1 = graph[0][i];
        pq.push(mp(t1.exp, t1.stt, t1.id));
    }
    while(!pq.empty()){
        Train t = pq.top();
        printf("State: %lf %lf %d\n", t.exp, t. stt, t.id);
        pq.pop();
        if (t.id==1)
            return t.exp;
        if (vis[t.id])
            continue;
        vis[t.id] = 1;
        //printf("SIZE: %d %d\n", t.id, graph[t.id].size());
        for (int i=0;i<graph[t.id].size();i++){
            Train t1 = graph[t.id][i];
            pq.push(mp(wait_time(t1.stt, t.stt)+t.exp+t1.exp, next_start(t1.stt, t1.exp), t1.id));
        }
    }
    return -1;
}

int main(){
    int t, ss, ds, mi, ti, pi, di;
    string s;
    char buf [25];
    scanf("%d", &t);
    //printf("Cases: %d\n", t);
    while(t--){
        cities = 0;
        scanf("%s", buf);
        //printf("Start: %s\n", buf);
        s = "";
        for (int i=0;i<strlen(buf);i++)
            s+=buf[i];
        nti[s] = cities++;
        scanf("%s", buf);
        //printf("Destination: %s\n", buf);
        s = "";
        for (int i=0;i<strlen(buf);i++)
            s+=buf[i];
        nti[s] = cities++;
        scanf("%d", &N);
        //printf("N: %d\n", N);
        for (int i=0;i<N;i++){
            scanf("%s", buf);
            //printf("S: %s\n", buf);
            s = "";
            for (int i=0;i<strlen(buf);i++)
                s+=buf[i];
            it = nti.find(s);
            if (it==nti.end()){
                nti[s] = cities++;
                ss = cities-1;
            }
            else ss = (*it).second;
            scanf("%s", buf);
            //printf("D: %s\n", buf);
            s = "";
            for (int i=0;i<strlen(buf);i++)
                s+=buf[i];
            it = nti.find(s);
            if (it==nti.end()){
                nti[s] = cities++;
                ds = cities-1;
            }
            else ds = (*it).second;
            scanf("%d %d %d %d", &mi, &ti, &pi, &di);
            //printf("INP: %d %d %d %d %d %d\n", ss, ds, mi, ti, pi, di);
            graph[ss].push_back(mp(expected(ti,pi,di),mi,ds));
        }
        double ddd = dijkstra();
        if (ddd==-1){
            printf("IMPOSSIBLE\n");
        }
        else printf("%lf\n", ddd);
        for (int i=0;i<cities;i++)
            graph[i].clear();
        nti.clear();
    }
}

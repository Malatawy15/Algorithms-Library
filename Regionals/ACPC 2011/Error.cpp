#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

#define City pair<int,pair<int,int> >
#define dis first
#define cost second.first
#define id second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))
#define Pair pair<int, int>

map<string, int> mp;
map<string, int>::iterator it;

map<Pair, int> mp1;
map<Pair, int>::iterator it1;

int N, M;
int vis[1000010];
int paid[1000010];

vector<Pair> graph[1000010];

int dij(int s, int d){
    priority_queue<City, vector<City>, greater<City> > pq;
    memset(vis,0,sizeof vis);
    pq.push(mp(0,0,s));
    while(!pq.empty()){
        City c = pq.top();
        pq.pop();
        if (c.id==d)
            return c.cost;
        if (vis[c.id])
            continue;
        vis[c.id] = 1;
        for (int i=0;i<graph[c.id].size();i++){
            Pair p = graph[c.id][i];
            if (!vis[p.first])
                pq.push(mp(c.dis+1,c.cost+(paid[p.second]==0?1:0),p.first));
        }
    }
    return -1;
}
/*
int solve(int s, int d){
    queue<City> q;
    memset(vis,0,sizeof vis);
    q.push(mp(0,0,s));
    while(!q.empty()){
        City c = q.front();
        q.pop();
        if (c.id==d)
            return c.cost;
        if (vis[c.id])
            continue;
        vis[c.id] = 1;
        for (int i=0;i<graph[c.id].size();i++){
            Pair p = graph[c.id][i];
            if (!vis[p.first])
                pq.push(mp(c.dis+1,c.cost+(paid[p.second]==0?1:0),p.first));
        }
    }
    return -1;
}

*/
int main(){
   // freopen("error.in","r",stdin);
    //freopen("error.txt","w",stdout);
    int t;
    scanf("%d", &t);
    string inp1, inp2;
    int i1, i2, edg, g, s, d;
    char buf[1000];
    while(t--){
        N = 0;
        edg = 0;
        scanf("%d", &M);
        for (int i=0;i<M;i++){
            scanf("%s", buf);
            inp1 = string(buf);
            scanf("%s", buf);
            inp2 = string(buf);
            it = mp.find(inp1);
            if (it!=mp.end()){
                i1 = it->second;
            }
            else {
                i1 = N++;
                mp.insert(make_pair(inp1, i1));
            }
            it = mp.find(inp2);
            if (it!=mp.end()){
                i2 = it->second;
            }
            else {
                i2 = N++;
                mp.insert(make_pair(inp2, i2));
            }
            mp1.insert(make_pair(Pair(i1,i2),edg));
            graph[i1].push_back(Pair(i2,edg++));
            mp1.insert(make_pair(Pair(i2,i1),edg));
            graph[i2].push_back(Pair(i1,edg++));
        }
        memset(paid, 0, sizeof paid);
        scanf("%d", &g);
        scanf("%s", buf);
        inp1 = string(buf);
        i1 = mp.find(inp1)->second;
        s = i1;
        for (int i=0;i<g;i++){
            scanf("%s", buf);
            inp2 = string(buf);
            i2 = mp.find(inp2)->second;
            paid[mp1.find(Pair(i1,i2))->second] = 1;
            //printf("Paid: %d %d\n",i1,i2);
            i1 = i2;
        }
        d = i2;
        //printf("Dij: %d %d\n",s,d);
        printf("%d\n",dij(s,d));
        for (int i=0;i<N;i++)
            graph[i].clear();
        mp.clear();
        mp1.clear();
    }
}

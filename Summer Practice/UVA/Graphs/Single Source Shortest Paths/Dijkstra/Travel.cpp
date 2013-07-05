#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<map>

using namespace std;

#define Node pair<int, int>
#define cost first
#define id second
#define Dij pair<int, pair<int, pair<int, int> > >
#define mp(a,b,c,d) make_pair(a, make_pair(b,make_pair(c,d)))
#define ct second.first
#define st second.second.first
#define ID second.second.second

int C, T;
map<string, int> m_c;
vector<Node> cities[110];
vector<Node> trains[110];
int vis[110];

void dijkstra(int start, int des, int est){
    priority_queue<Dij, vector<Dij>, greater<Dij> > pq;
    memset(vis, 0, sizeof vis);
    for (int i=0;i<cities[start].size();i++){
        Node n = cities[start][i];
        if (n.cost>=est)
            pq.push(mp(0, n.cost, n.cost, start));
    }
    int min = -1;
    Dij dij;
    while(!pq.empty()){
        Dij d = pq.top();
        pq.pop();
        if (min!=-1)
            if (d.cost>min){
                if (dij.st<1000)
                    printf("0%d ", dij.st);
                else printf("%d ", dij.st);
                if (dij.ct<1000)
                    printf("0%d\n", dij.ct);
                else printf("%d\n", dij.ct);
                return;
            }
            else {
                dij = d;
                continue;
            }
        else if (d.ID==des){
            min = d.cost;
            dij = d;
        }
        if (vis[d.ID])
            continue;
        vis[d.ID] = 1;
        for (int i=0;i<cities[d.ID].size();i++){
            Node n = cities[d.ID][i];
            if (n.cost>=d.ct){
                for (int j=0;j<trains[n.id].size();j++){
                    Node n1 = trains[n.id][j];
                    if (n1.cost>=d.ct)
                        pq.push(mp(d.cost+(n1.cost-d.ct),n1.cost, d.st, n1.id));
                }
            }
        }
    }
    printf("No connection\n");
}

string make_string(char* cp){
    string s1 = "";
    for (int i=0;i<strlen(cp);i++)
        s1+=cp[i];
    return s1;
}

int main(){
    char name[21];
    scanf("%d", &C);
    while(C){
        for (int i=0;i<C;i++){
            scanf("%s", name);
            m_c.insert(make_pair(make_string(name), i));
        }
        int ti, times;
        scanf("%d", &T);
        for (int i=0;i<T;i++)
            trains[i].clear();
        for (int i=0;i<C;i++)
            cities[i].clear();
        for(int i=0;i<T;i++){
            scanf("%d", &ti);
            while(ti--){
                scanf("%d %s", &times, name);
                int ind = m_c[make_string(name)];
                cities[ind].push_back(Node(times, i));
                trains[i].push_back(Node(times, ind));
            }
        }
        int stime, snode, enode;
        scanf("%d", &stime);
        scanf("%s", name);
        snode = m_c[make_string(name)];
        scanf("%s", name);
        enode = m_c[make_string(name)];
        //printf("CALL: %d %d %d\n", snode,enode,stime);
        dijkstra(snode, enode, stime);
        //printf("END CALL\n");
        scanf("%d", &C);
    }
}

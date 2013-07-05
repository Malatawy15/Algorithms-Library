#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

#define Jugs pair<int, pair<int, pair<int, int> > >
#define cost first
#define A second.first
#define B second.second.first
#define C second.second.second
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))

int vis[210][210][210];
int closest, target, mcost;

int update(Jugs j){
    if (abs(j.A-target)<abs(closest-target)){
        closest = j.A;
        mcost = j.cost;
    }
    if (abs(j.B-target)<abs(closest-target)){
        closest = j.B;
        mcost = j.cost;
    }
    if (abs(j.C-target)<abs(closest-target)){
        closest = j.C;
        mcost = j.cost;
    }
    if (closest==target)
        return 1;
    return 0;
}

void dijkstra(int a, int b, int c){
    priority_queue<Jugs, vector<Jugs>, greater<Jugs> >pq;
    pq.push(mp(0,0,0,c));
    memset(vis, 0, sizeof vis);
    while(!pq.empty()){
        Jugs j = pq.top();
        pq.pop();
        if (update(j))
            break;
        if (vis[j.A][j.B][j.C])
            continue;
        vis[j.A][j.B][j.C] = 1;
        if (j.A>b-j.B)
            pq.push(mp(j.cost+(b-j.B), (j.A-(b-j.B)), b, j.C));
        else pq.push(mp(j.cost+j.A,0,j.B+j.A, j.C));
        if (j.A>c-j.C)
            pq.push(mp(j.cost+(c-j.C), (j.A-(c-j.C)), j.B, c));
        else pq.push(mp(j.cost+j.A,0, j.B, j.C+j.A));
        if (j.B>a-j.A)
            pq.push(mp(j.cost+(a-j.A), a, (j.B-(a-j.A)), j.C));
        else pq.push(mp(j.cost+j.B,j.B+j.A,0, j.C));
        if (j.B>c-j.C)
            pq.push(mp(j.cost+(c-j.C),j.A, (j.B-(c-j.C)), c));
        else pq.push(mp(j.cost+j.B, j.A,0, j.C+j.B));
        if (j.C>a-j.A)
            pq.push(mp(j.cost+(a-j.A), a, j.B, (j.C-(a-j.A))));
        else pq.push(mp(j.cost+j.C,j.C+j.A, j.B, 0));
        if (j.C>b-j.B)
            pq.push(mp(j.cost+(b-j.B),j.A, b, (j.C-(b-j.B))));
        else pq.push(mp(j.cost+j.C, j.A, j.C+j.B, 0));
    }
    printf("%d %d\n", mcost, closest);
}

int main(){
    int T,a,b,c;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &a, &b, &c, &target);
        closest = 0;mcost = 0;
        dijkstra(a,b,c);
    }
}

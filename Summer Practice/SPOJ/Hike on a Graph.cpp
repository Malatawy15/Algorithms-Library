#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define Config pair<int, pair<int, pair<int, int> > >
#define A first
#define B second.first
#define C second.second.first
#define cost second.second.second
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))

int vis[50][50][50];
char colors[50][50];

int N, p1, p2, p3;

int bfs(){
    int ind;
    memset(vis,0,sizeof vis);
    queue<Config> q;
    q.push(mp(p1,p2,p3,0));
    while(!q.empty()){
        Config c = q.front();
        q.pop();
        if (c.A==c.B&&c.B==c.C)
            return c.cost;
        if (vis[c.A][c.B][c.C])
            continue;
        vis[c.A][c.B][c.C] = 1;
        for (int i=0;i<N;i++){
            if (i!=c.A&&colors[c.A][i]==colors[c.B][c.C])
                q.push(mp(i,c.B,c.C,c.cost+1));
            if (i!=c.B&&colors[c.B][i]==colors[c.A][c.C])
                q.push(mp(c.A,i,c.C,c.cost+1));
            if (i!=c.C&&colors[c.C][i]==colors[c.A][c.B])
                q.push(mp(c.A,c.B,i,c.cost+1));
        }
    }
    return -1;
}

int main(){
    cin>>N;
    while(N){
        cin>>p1>>p2>>p3;
        p1--;p2--;p3--;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                cin>>colors[i][j];
        int ans = bfs();
        if (ans==-1)
            printf("impossible\n");
        else printf("%d\n",ans);
        cin>>N;
    }
}

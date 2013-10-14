#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

#define Pair pair<int, int>
#define num first
#define cost second

int vis[10001];
int isPrime[10001];

void sieve(){
    memset(isPrime, 0, sizeof isPrime);
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2;i*i<=10000;i++){
        if (!isPrime[i]){
            for (int j = i*i;j<=10000;j+=i)
                isPrime[j] = 1;
        }
    }
}

int rep1st(int num, int n){
    return num/10*10+n;
}

int rep2nd(int num, int n){
    int nn = num/100*100, nnn = num%10;
    return nn+n*10+nnn;
}

int rep3rd(int num, int n){
    int nn = num/1000*1000, nnn = num%100;
    return nn+n*100+nnn;
}

int rep4th(int num, int n){
    int nnn = num%1000;
    return n*1000+nnn;
}

int bfs(int s, int d){
    queue<Pair> q;
    q.push(Pair(s,0));
    memset(vis,0,sizeof vis);
    while(!q.empty()){
        Pair p = q.front();
        q.pop();
        if (p.num==d)
            return p.cost;
        if (vis[p.num])
            continue;
        vis[p.num] = 1;
        int nn;
        for (int i = 0; i<10; i++){
            nn = rep1st(p.num, i);
            if (!isPrime[nn]&&!vis[nn])
                q.push(make_pair(nn,p.cost+1));
            nn = rep2nd(p.num, i);
            if (!isPrime[nn]&&!vis[nn])
                q.push(make_pair(nn,p.cost+1));
            nn = rep3rd(p.num, i);
            if (!isPrime[nn]&&!vis[nn])
                q.push(make_pair(nn,p.cost+1));
            if (i){
                nn = rep4th(p.num, i);
                if (!isPrime[nn]&&!vis[nn])
                    q.push(make_pair(nn,p.cost+1));
            }
        }
    }
    return -1;
}

int main(){
    sieve();
    int t, s, d;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &s, &d);
        int res = bfs(s,d);
        if (res!=-1)
            printf("%d\n", res);
        else printf("Impossible\n");
    }
}

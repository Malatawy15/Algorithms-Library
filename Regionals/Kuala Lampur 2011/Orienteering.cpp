#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int INF = -100000000;
int N;

//int dp[31][10010];
map<pair<int, double>, int> dp;
map<pair<int, double>, int>::iterator it;
int pts[31][2];
int scores[31];

double rnd (double n){
    return floor(n * 100 + 0.5)/100.0;
}

double dis(int i, int j){
    return hypot(abs(pts[i][0]-pts[j][0]),abs(pts[i][1]-pts[j][1]));
}

int maximize(int n, double rem){
    //printf("%d %d %lf\n", n, N, rnd(rem));
    if (n==N){
        if (dis(0,n)<=rem)
            return 0;
        else return INF;
    }
    //printf("GO FINDER\n");
    it = dp.find(make_pair(n,rnd(rem)));
    if (it!=dp.end()){
        //printf("FOUND\n");
        return (*it).second;
    }
    int maxi = INF;
    if (dis(n,0)<=rem)
        maxi = 0;
    //printf("CALL READY!\n");
    for (int i=n+1;i<=N;i++){
        //printf("DIST: %d %d %lf\n",n,i,dis(n,i));
        if (dis(n,i)<=rem)
            maxi = max(maxi, scores[i]+maximize(i,rem-dis(n,i)));
    }
    dp[make_pair(n,rnd(rem))] = maxi;
    return maxi;
}

int main(){
    pts[0][0] = 0;
    pts[0][1] = 1;
    scanf("%d", &N);
    char name[65];
    int cs = 1;
    double dist;
    while(N){
        dp.clear();
        for (int i=1;i<=N;i++)
            scanf("%d %d %d", &pts[i][0], &pts[i][1], &scores[i]);
        scanf("%s %lf", name, &dist);
        printf("Race %d\n", cs++);
        while(strcmp(name, "#")!=0){
            printf("%s: %d\n", name, maximize(0, dist));
            scanf("%s %lf", name, &dist);
        }
        dp.clear();
        scanf("%d", &N);
    }
}

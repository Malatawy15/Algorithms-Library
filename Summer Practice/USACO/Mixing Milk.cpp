/*
ID: malataw1
PROG: milk
LANG: C++
*/

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;

int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int N, M, x, y;
    vector<ii> v;
    scanf("%d %d", &N, &M);
    N = -N;
    for (int i=0;i<M;i++){
        scanf("%d %d", &x, &y);
        v.push_back(ii(x,-y));
    }
    sort(v.begin(),v.end());
    int i=0, sum = 0;
    while(N<0){
        if (v[i].second>N){
            N-=v[i].second;
            sum-=(v[i].first*v[i].second);
        }
        else {
            sum-=(v[i].first*N);
            N = 0;
        }
        i++;
    }
    printf("%d\n",sum);
}

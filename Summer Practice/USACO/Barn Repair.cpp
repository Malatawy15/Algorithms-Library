/*
ID: malataw1
PROG: barn1
LANG: C++
*/

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;

int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int M, S, C, x;
    vector<ii> v;
    vector<int> v1,v2;
    scanf("%d %d %d", &M, &S, &C);
    for (int i=0;i<C;i++){
        scanf("%d", &x);
        v1.push_back(x);
    }
    sort(v1.begin(),v1.end());
    for (int i=1;i<C;i++){
        v.push_back(ii(v1[i]-v1[i-1],i));
    }
    sort(v.begin(),v.end());
    int sum = 0, ss = v.size();
    M = min(M-1,C-1);
    for (int i=0;i<M;i++)
        v2.push_back(v[ss-1-i].second);
    sort(v2.begin(),v2.end());
    int s = v1[0], e = v1[0], j = 0;
    for (int i=1;i<C;i++){
        if (j<v2.size()&&v1[i]==v1[v2[j]]){
            e = v1[i-1];
            //printf("MATCH: %d %d %d %d\n",v1[i],v1[v2[j]],s,e);
            sum+=(e-s+1);
            s = v1[i];
            j++;
        }
    }
    e = v1[v1.size()-1];
    sum+=(e-s+1);
    printf("%d\n",sum);
}

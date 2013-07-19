#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define Flight pair<int, pair<int, int> >
#define t first
#define se second.first
#define ind second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int N;
vector<Flight> both;
vector<Flight>::iterator it;
vector<Flight> start;
int taken[10010];
int vals[10010][3];

int maximize(int n){
    if (n==N)
        return 0;
    if (taken[n]!=-1)
        return taken[n];
    int sum = -1, index = start[n].ind;
    sum = vals[index][2];
    it = lower_bound(both.begin(), both.end(), mp(vals[index][0]+vals[index][1], 0, n));
    for (;it!=both.end();++it)
        if((*it).se==1){
            sum += maximize((*it).ind);
            break;
        }
    sum = max(sum, maximize(n+1));
    taken[n] = sum;
    return sum;
}

int main(){
    int t,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for (int i=0;i<N;i++){
            scanf("%d %d %d",&x,&y,&z);
            vals[i][0] = x;
            vals[i][1] = y;
            vals[i][2] = z;
            start.push_back(mp(x,0,i));
        }
        sort(start.begin(),start.end());
        for (int i=0;i<start.size();i++){
            int j = start[i].ind;
            both.push_back(mp(vals[j][0],1,i));
            both.push_back(mp(vals[j][0]+vals[j][1], 0, i));
        }
        sort(both.begin(),both.end());
        memset(taken,-1,sizeof taken);
        printf("%d\n",maximize(0));
        both.clear();
        start.clear();
    }
}


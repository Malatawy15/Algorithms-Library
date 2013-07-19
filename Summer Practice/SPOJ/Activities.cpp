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
#define MOD 100000000

int N;
vector<Flight> both;
vector<Flight> start;
int taken[100010];
int counted[100010];
int next[100010];
int vals[100010][2];
int main(){
    int t,x,y;
    scanf("%d",&N);
    while(N!=-1){
        for (int i=0;i<N;i++){
            scanf("%d %d",&x,&y);
            vals[i][0] = x;
            vals[i][1] = y;
            start.push_back(mp(x,0,i));
        }
        sort(start.begin(),start.end());
        for (int i=0;i<start.size();i++){
            int j = start[i].ind;
            both.push_back(mp(vals[j][0],1,i));
            both.push_back(mp(vals[j][1],0,i));
        }
        sort(both.begin(),both.end());
        int latest = -1;
        for (int i=both.size()-1;i>=0;i--)
            if (both[i].se==0)
                next[both[i].ind] = latest;
            else latest = both[i].ind;
        taken[N] = 0;
        counted[N] = 0;
        for (int i=N-1;i>=0;i--){
            if (next[i]==-1)
                taken[i] = 1;
            else taken[i] = 1+counted[next[i]];
            counted[i] = (counted[i+1]+(taken[i])%MOD)%MOD;
        }
        printf("%08d\n",counted[0]);
        both.clear();
        start.clear();
        scanf("%d",&N);
    }
}

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

int C, V;

vector<vector<int> > pref;

int main(){
    int t,a;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &C, &V);
        pref.clear();
        for (int i=0;i<V;i++){
            pref.push_back(vector<int> ());
            for (int j=0;j<C;j++){
                scanf("%d", &a);
                pref[i].push_back(a);
            }
        }
        vector<pair<int, int> > v;
        vector<int> ct(C+2, 0);
        for (int i=0;i<V;i++){
            ct[pref[i][0]]++;
        }
        for (int i=1;i<=C;i++){
            v.push_back(make_pair(ct[i],i));
        }
        sort(v.begin(), v.end());
        if (v[C-1].first>=(V>>1)+1){
            printf("%d %d\n", v[C-1].second, 1);
            continue;
        }
        int c1 = 0, c2 = 0, d1 = v[C-2].second, d2=v[C-1].second;
        for (int i=0;i<V;i++){
            for (int j=0;j<C;j++)
            if (pref[i][j]==d1){
                c1++;
                break;
            }
            else if (pref[i][j]==d2){
                c2++;
                break;
            }
        }
        if (c1>c2){
            printf("%d %d\n",d1,2);
        }
        else {
            printf("%d %d\n",d2,2);
        }
    }
}

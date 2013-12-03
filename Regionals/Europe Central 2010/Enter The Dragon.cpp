#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> lakes, sol, q, tk, tmk;
set<int> av;
set<int>::iterator it;

int check(){
    for (int i=0;i<q.size();i++){
        int lk = q[i];
        if (!lakes[lk]){
            lakes[lk] = 1;
            tmk[lk] = tk[i];
        }
        else {
            it = av.lower_bound(tmk[lk]);
            if (it==av.end())
                return 0;
            if ((*it)>tk[i])
                return 0;
            sol[(*it)] = lk;
            //printf("HERE: %d %d\n",(*it),lk);
            av.erase(it);
            tmk[lk] = tk[i];
        }
    }
    return 1;
}

int main(){
    int t, n, m, rem, a;
    scanf("%d", &t);
    while(t--){
        rem = 0;
        sol.clear();
        lakes.clear();
        q.clear();
        av.clear();
        tk.clear();
        tmk.clear();
        scanf("%d %d", &n, &m);
        lakes = vector<int> (n+1,1);
        tmk = vector<int> (n+1,0);
        sol = vector<int> (m+1,0);
        vector<int> times;
        for (int i=1;i<=m;i++){
            scanf("%d", &a);
            if (a){
                q.push_back(a);
                tk.push_back(i);
            }
            else{
                av.insert(i);
                times.push_back(i);
                //sol.push_back(0);
            }
        }
        int l = av.size();
        if (check()){
            printf("YES\n");
            printf("%d", sol[times[0]]);
            for (int i=1;i<l;i++)
                printf(" %d",sol[times[i]],times[i]);
            printf("\n");
        }
        else {
            printf("NO\n");
        }
    }
}

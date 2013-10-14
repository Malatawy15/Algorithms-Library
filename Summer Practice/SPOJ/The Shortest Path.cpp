#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<string>
#include<map>

using namespace std;

#define High pair<int,int>
#define sfi pair<string,int>
#define id second
#define csf first


vector<High> a [10010];
int b [10010];
int cdd [101][10010];
int d12 [10010];

void dij(int s, int n, int ind) {
    d12[s] = 0;
    priority_queue<High, vector<High>, greater<High> > pq;
    pq.push(High(0, s));
    while (!pq.empty()) {
        int ID = pq.top().id;
        int c = pq.top().csf;
        pq.pop();
        if (b[ID]) {
                continue;
        }
        b[ID] = 1;
        int size1 = a[ID].size();
        for (int i = 0; i < size1; i++) {
            if (!b[a[ID][i].id]&&d12[a[ID][i].id]>a[ID][i].csf +c) {
                pq.push(High( a[ID][i].csf +c,a[ID][i].id));
                d12[a[ID][i].id] = a[ID][i].csf +c;
            }
        }
    }
    for (int i=0;i<n+5;i++)
        cdd[ind][i] = d12[i]==2147483647?-1:d12[i];
}

int main(){
    int s,n,p,r,nr,co,start,end;
    char c [20];
    map< string, int > M;
    map< string, int > :: iterator it;
    map<int, int> mmm;
    map<int, int> :: iterator mmit;
    scanf("%d",&s);
    for (int k =0;k<s;k++){
        mmm.clear();
        M.clear();
        scanf("%d",&n);
        for (int i = 0; i < n+1; i++) {
            a[i].clear();
        }
        for (int i =1;i<=n;i++){
            scanf("%s",&c);
            M.insert(sfi(c,i));
            scanf("%d",&p);
            for (int j =0;j<p;j++){
                scanf("%d %d",&nr,&co);
                a[i].push_back(High(co,nr));
            }
        }
        int ind = 0;
        scanf("%d",&r);
        for (int i =0;i<r;i++){
            scanf("%s", c);
            it = M.find(c);
            start = (*it).second;
            mmit = mmm.find(start);
            scanf("%s", c);
            it = M.find(c);
            end = (*it).second;
            if (mmit==mmm.end()){
                mmm.insert(make_pair(start,ind));
                for (int i = 0; i < n+5; i++) {
                    b[i] = 0;
                    d12[i] = 2147483647;
                }
                dij(start,n, ind);
                printf("%d\n",cdd[ind][end]);
                ind++;
            }
            else printf("%d\n",cdd[(*mmit).second][end]);
        }
    }
}



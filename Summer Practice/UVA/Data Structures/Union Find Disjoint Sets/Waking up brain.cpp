#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>

using namespace std;

int N, M;
int wk[28];
int cn[28];
vector<int> up;
vector<int> gr[28];

int calc(){
    memset(wk,0,sizeof wk);
    memset(cn,0,sizeof cn);
    int sum = -1;
    while(!up.empty()){
        for (int i=0;i<up.size();i++){
            wk[up[i]] = 1;
            for (int j=0;j<gr[up[i]].size();j++)
                cn[gr[up[i]][j]]++;
        }
        up.clear();
        sum++;
        for (int i=0;i<N;i++)
            if (!wk[i]&&cn[i]>=3)
                up.push_back(i);
    }
    for (int i=0;i<N;i++)
        if (!wk[i])
            return -1;
    return sum;
}

int main(){
    char buf[5];
    map<char, int> mp;
    map<char, int>::iterator it;
    while(scanf("%d", &N)>0){
        scanf("%d", &M);
        scanf("%s", buf);
        mp.clear();
        up.clear();
        for (int i=0;i<N;i++)
            gr[i].clear();
        int ind = 0, x, y;
        mp.insert(make_pair(buf[0], ind++));
        mp.insert(make_pair(buf[1], ind++));
        mp.insert(make_pair(buf[2], ind++));
        up.push_back(0);
        up.push_back(1);
        up.push_back(2);
        for (int i=0;i<M;i++){
            scanf("%s", buf);
            it = mp.find(buf[0]);
            if (it==mp.end()){
                x = ind++;
                mp.insert(make_pair(buf[0],x));
            }
            else x = it->second;
            it = mp.find(buf[1]);
            if (it==mp.end()){
                y = ind++;
                mp.insert(make_pair(buf[1],y));
            }
            else y = it->second;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        x = calc();
        if (x==-1)
            printf("THIS BRAIN NEVER WAKES UP\n");
        else printf("WAKE UP IN, %d, YEARS\n", x);
    }
}

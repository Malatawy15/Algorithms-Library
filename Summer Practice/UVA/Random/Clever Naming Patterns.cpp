#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

typedef vector<int> vi;

#define MAX_V 70
#define INF 1000000000

int N;
//int res[MAX_V][MAX_V], mf, f, s, t;
vi owner, vis;
vector<vector<string> > names;
vector<vi> graph;

int alt_path(int left){
    if (vis[left]) return 0;
    vis[left] = 1;
    for (int j=0;j<graph[left].size();j++){
        int right = graph[left][j];
        if (owner[right]==-1||alt_path(owner[right])){
            owner[right] = left;
            return 1;
        }
    }
    return 0;
}

int main(){
    int tt,cnt;
    string s;
    cin>>tt;
    for (int k=1;k<=tt;k++){
        cin>>N;
        names.clear();
        graph.clear();
        owner.clear();
        vis.clear();
        for (int i=0;i<N;i++){
            cin>>cnt;
            names.push_back(vector<string>());
            graph.push_back(vi());
            while(cnt--){
                cin>>s;
                s[0] = toupper(s[0]);
                for (int kk=1;kk<s.size();kk++)
                    s[kk] = tolower(s[kk]);
                if (s[0]-'A'>=N)
                    continue;
                names[i].push_back(s);
                graph[i].push_back(s[0]-'A');
            }
        }
        owner.assign(N,-1);
        for (int left = 0;left<N;left++){
            vis.clear();
            vis.assign(N,0);
            alt_path(left);
        }
        printf("Case #%d:\n",k);
        for (int i=0;i<owner.size();i++){
            if (owner[i]!=-1){
                for (int j=0;j<names[owner[i]].size();j++)
                    if (names[owner[i]][j][0]-'A'==i){
                        printf("%s\n",names[owner[i]][j].c_str());
                        break;
                    }
            }
        }
    }
}

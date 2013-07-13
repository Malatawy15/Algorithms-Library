#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>

using namespace std;

vector<int> graph[5010];
pair<int, int> countC[5010];
int vis[5010];
int anc[5010];
int N, D, C;
vector<int> nodes;
map<string,int> nti;
map<string,int>::iterator it1;
map<int,string> itn;
map<int,string>::iterator it2;


void dfs(int node, int depth){
    if (vis[node])
        return;
    vis[node] = 1;
    if (depth>=D)
        countC[nodes[depth-D]].first--;
    nodes.push_back(node);
    for (int i=0;i<graph[node].size();i++)
        dfs(graph[node][i],depth+1);
    nodes.pop_back();
}

void print_result(){
    int ind = 0, fir;
    while(ind<C&&countC[ind].first<0&&ind<3){
        fir = countC[ind].first;
        vector<string> vec;
        while(ind<C&&countC[ind].first==fir){
            vec.push_back(itn[countC[ind].second]);
            ind++;
        }
        sort(vec.begin(),vec.end());
        fir*=-1;
        for (int i=0;i<vec.size();i++)
            printf("%s %d\n",vec[i].c_str(),fir);
        vec.clear();
    }
}

int main(){
    int t,ind,fol,ind1;
    string name;
    //scanf("%d",&t);
    cin>>t;
    for (int k=1;k<=t;k++){
        C = 0;
        memset(vis,0,sizeof vis);
        memset(anc,0,sizeof anc);
        //scanf("%d %d",&N,&D);
        cin>>N>>D;
        for (int i=0;i<N;i++){
            //scanf("%s",name);
            cin>>name;
            it1 = nti.find(name);
            if (it1==nti.end()){
                nti.insert(make_pair(name, C));
                itn.insert(make_pair(C, name));
                ind = C;
                C++;
            }
            else{
                ind = it1->second;
            }
            cin>>fol;
            for (int j=0;j<fol;j++){
                cin>>name;
                it1 = nti.find(name);
                if (it1==nti.end()){
                    nti.insert(make_pair(name, C));
                    itn.insert(make_pair(C, name));
                    ind1 = C;
                    C++;
                }
                else{
                    ind1 = it1->second;
                }
                anc[ind1] = 1;
                graph[ind].push_back(ind1);
            }
        }
        for (int i=0;i<C;i++)
            countC[i] = make_pair(0,i);
        for (int i=0;i<C;i++)
            if (!anc[i]){
                ind = i;
                break;
            }
        dfs(ind,0);
        sort(countC,countC+C);
        printf("Tree %d:\n",k);
        print_result();
        for (int i=0;i<C;i++)
            graph[i].clear();
        nodes.clear();
        nti.clear();
        itn.clear();
    }
}

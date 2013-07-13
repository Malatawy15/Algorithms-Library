#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define INF 1000000000

int sp[101][101];
int N, C, R;
map<string,int> nti;
map<string,int>::iterator it;

void reset(){
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            sp[i][j] = INF;
}

void floyd_warshall(){
    for (int k=0;k<N;k++)
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                sp[i][j] = min(sp[i][j],sp[i][k]+sp[k][j]);
}

void add_edge(string n1, string arrow, string n2){
    int i1 = nti[n1], i2 = nti[n2], cost=0;
    if (arrow[0]=='-'){
        sscanf(arrow.c_str(),"--%d->",&cost);
        sp[i1][i2] = min(sp[i1][i2],cost);
    }
    else if (arrow[arrow.size()-1]=='-'){
        sscanf(arrow.c_str(),"<-%d--",&cost);
        sp[i2][i1] = min(sp[i2][i1],cost);
    }
    else{
        sscanf(arrow.c_str(),"<-%d->",&cost);
        sp[i1][i2] = min(sp[i1][i2],cost);
        sp[i2][i1] = min(sp[i2][i1],cost);
    }
}

int main(){
    cin>>N>>C>>R;
    string n1, n2, arrow;
    int cases = 1;
    while(!(N==0&&C==0&&R==0)){
        vector<int> path;
        int ind = 0;
        reset();
        for (int i=0;i<=C;i++){
            cin>>n1;
            it = nti.find(n1);
            if (it==nti.end()){
                nti.insert(make_pair(n1,ind));
                path.push_back(ind);
                ind++;
            }
            else path.push_back(it->second);
        }
        for (int i=0;i<R;i++){
            cin>>n1;
            cin>>arrow;
            cin>>n2;
            it = nti.find(n1);
            if (it==nti.end()){
                nti.insert(make_pair(n1,ind));
                ind++;
            }
            it = nti.find(n2);
            if (it==nti.end()){
                nti.insert(make_pair(n2,ind));
                ind++;
            }
            add_edge(n1,arrow,n2);
        }
        floyd_warshall();
        int garage = path[0], sum = 0;
        for (int i=1;i<path.size();i++){
            if (path[i]!=garage)
                sum+=sp[garage][path[i]]+sp[path[i]][garage];
        }
        printf("%d. %d\n", cases++, sum);
        nti.clear();
        cin>>N>>C>>R;
    }
}

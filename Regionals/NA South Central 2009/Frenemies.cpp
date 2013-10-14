#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int N, st;
char matrix [9][9];
string names[9];
int vis [9];
int scores [9];
int pows [8];

void dfs(int node, int len, int ne, int nf){
    if (vis[node])
        return;
    vis[node] = 1;
    if (node!=st){
        scores[node]+=((ne%2==0?128:-128)/pows[len-1]);
    }
    for (int i=0;i<N;i++)
        if (matrix[node][i]!='N')
            dfs(i,len+1,ne+(matrix[node][i]=='E'),nf+(matrix[node][i]=='F'));
    vis[node] = 0;
}

int main(){
    pows[0] = 1;
    for (int i=1;i<8;i++)
        pows[i] = pows[i-1]<<1;
    int t;
    char c;
    string s;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        memset(scores,0,sizeof scores);
        cin>>N;
        //cout<<"N: "<<N<<endl;
        for (int i=0;i<N;i++){
            cin>>names[i];
            for (int j=0;j<N;j++)
                cin>>matrix[i][j];
        }
        cin>>s;
        //cout<<"S: "<<s<<endl;
        for (st = 0;st<N;st++)
        if (names[st].compare(s)==0)
            break;
        //cout<<"ST: "<<st<<endl;
        dfs(st,0,0,0);
        for (int i=0;i<N;i++)
            if (i)
                cout<<" "<<scores[i];
            else cout<<scores[i];
        cout<<endl;
    }
}

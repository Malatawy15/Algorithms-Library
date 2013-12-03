/*
ID: malataw1
PROG: calfflac
LANG: C++
*/

#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;

string in;
int size;

int isLetter(char c){
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}

int isUpper(char c){
    return (c>='A'&&c<='Z');
}

char toLower(char c){
    return isUpper(c)?c+32:c;
}

ii palin(int s, int e){
    //cout<<"PALIN: "<<s<<" "<<e<<endl;
    int len = e-s+1, ls = s;
    s--;e++;
    ls = s;
    while(1){
        if (e==size||s==-1||toLower(in[s])!=toLower(in[e])) break;
        ls = s;
        len+=2;
        s--;
        e++;
    }
    //cout<<"RET: "<<ls<<" "<<len<<endl;
    return ii(len,-(ls));
}

int main(){
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    char buf [100];
    string st, inp;
    inp = "";
    in = "";
    int arr[20010];
    while(gets(buf)) inp+=(string(buf)+"\n");
    size = inp.size();
    int j = 0;
    for (int i=0;i<size;i++) if (isLetter(inp[i])) in+=inp[i], arr[j++] = i;
    size = in.size();
    vector<ii> v;
    for (int i=0;i<size;i++){
        if (i<size-1) if (toLower(in[i])==toLower(in[i+1]))v.push_back(palin(i,i+1));
        v.push_back(palin(i,i));
    }
    sort(v.begin(), v.end());
    int s = arr[v[v.size()-1].second * -1], len = v[v.size()-1].first;
    cout<<len<<endl;
    while(!isLetter(inp[s]))s++;
    //while(!isLetter(inp[e]))e--;
    //cout<<inp<<endl;
    //cout<<s<<" "<<v[v.size()-1].first<<endl;
    while(len>0){
        if (isLetter(inp[s])) len--;
        cout<<inp[s];
        s++;
    }
    if (inp[s-1]!='\n')
        cout<<endl;
    //cout<<inp.substr(s,e-s+1)<<endl;
    //printf("\n");
}

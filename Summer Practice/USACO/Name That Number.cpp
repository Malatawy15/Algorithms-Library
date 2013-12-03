/*
ID: malataw1
PROG: namenum
LANG: C++
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<fstream>

using namespace std;

int N;
string num;
vector<string>res;
vector<string>keys;
set<string>valid;

void generate(int n, string s){
    //cout<<"Call: "<<n<<" "<<s<<endl;
    if (n==N){
        if (valid.find(s)!=valid.end())
            res.push_back(s);
        return;
    }
    for (int i=0;i<3;i++)
        generate(n+1,s+keys[num[n]-'2'][i]);
}

int main(){
    ifstream file("dict.txt");
    while(getline(file, num))
        valid.insert(num);
    file.close();
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    keys.push_back("ABC");
    keys.push_back("DEF");
    keys.push_back("GHI");
    keys.push_back("JKL");
    keys.push_back("MNO");
    keys.push_back("PRS");
    keys.push_back("TUV");
    keys.push_back("WXY");
    cin>>num;
    N = num.size();
    //cout<<N<<endl;
    generate(0,"");
    if (res.size()>0)
    for (int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    else cout<<"NONE"<<endl;
}

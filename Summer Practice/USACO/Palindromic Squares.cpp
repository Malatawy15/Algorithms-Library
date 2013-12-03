/*
ID: malataw1
PROG: palsquare
LANG: C++
*/

#include<stdio.h>
#include<string>

using namespace std;

int b;

int palin(string s){
    int n = s.size();
    for (int i=0;i<(n>>1);i++){
        if (s[i]!=s[n-i-1])
            return 0;
    }
    return 1;
}

void check(int n){
    string s = "", s1 = "";
    int nn = n*n;
    while(nn>0){
        int mn = nn%b;
        nn/=b;
        if (mn<10) s = ((char)(mn+'0')) + s;
        else s = ((char)((mn-10)+'A')) + s;
    }
    while(n>0){
        int mn = n%b;
        n/=b;
        if (mn<10) s1 = ((char)(mn+'0')) + s1;
        else s1 = ((char)((mn-10)+'A')) + s1;
    }
    if (palin(s))
        printf("%s %s\n",s1.c_str(),s.c_str());
}

int main(){
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    scanf("%d", &b);
    for (int i=1;i<=300;i++)
        check(i);
}

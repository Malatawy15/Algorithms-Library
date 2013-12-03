/*
ID: malataw1
PROG: dualpal
LANG: C++
*/

#include<stdio.h>
#include<string>

using namespace std;


int N, S;


int palin(string s){
    int n = s.size();
    for (int i=0;i<(n>>1);i++){
        if (s[i]!=s[n-i-1])
            return 0;
    }
    return 1;
}


int check(int n){
    int f = 0, nn;
    string s;
    for (int b=2;b<=10;b++){
        s = "";
        nn = n;
        while(nn>0){
            s = ((char)((nn%b)+'0')) + s;
            nn/=b;
        }
        if (palin(s)){
            if (f)
                return 1;
            else f = 1;
        }
    }
    return 0;
}

int main(){
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    scanf("%d %d", &N, &S);
    while(N>0){
        S++;
        if (check(S)){
            N--;
            printf("%d\n", S);
        }
    }
}

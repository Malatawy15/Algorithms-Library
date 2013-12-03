#include<stdio.h>
#include<iostream>
#include<string>
#include<bitset>

using namespace std;

int check(){
    string s;
        cin>>s;
        s = '0' + s + '0';
        for (int i=1;i<s.size()-1;i++){
            if ((s[i-1]=='1'&&s[i+1]=='0')||(s[i+1]=='1'&&s[i-1]=='0')){
                return 1;
            }
        }
        return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        if (check()){
            printf("LIVES\n");
        }
        else printf("DIES\n");
    }
}

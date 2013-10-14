#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//int dp[10][1000010][2];
int vals[10];
int nums[10];

string finder(int n, int b){
  //  printf("%d\n", b);
    if (b==0)
        return "";
    for (int i=1;i<=9;i++){
        nums[i] = b/vals[i];
    }
    int fl = -1, mi;
    for (int i=9;i>=1;i--)
        if(nums[i]>fl){
            fl = nums[i];
            mi = i;
        }
    if (fl==0){
        return "";
    }
    string out (nums[mi],(char)('0'+mi));
    b = b - vals[mi]*nums[mi];
    string s1 = finder(b);
    if (s1.size()==0)
        return out;
    else if (s1[0]-'0'<mi)
        return out + s1;
    else return s1+out;
}



/*
int maximize(int n, int rem){
    if (n==0)
        return 0;
        printf("%d %d\n", n, rem);
    if (dp[n][rem][0]!=-1)
        return dp[n][rem][0];
    dp[n][rem][0] = maximize(n-1,rem);
    dp[n][rem][1] = 0;
    int num = 0, bu = rem;
    while(bu>=vals[n]){
        bu-=vals[n];
        num++;
        int ret = num+maximize(n-1, bu);
        if (ret>=dp[n][rem][0]){
            dp[n][rem][0] = ret;
            dp[n][rem][1] = num;
        }
    }
    return dp[n][rem][0];
}

string recur(int n, int rem){
    string ret = "";
    if (n==0)
        return ret;
    for (int i=0;i<dp[n][rem][1];i++)
        ret = ret + (char)('0'+n);
    return ret + recur(n-1,rem-dp[n][rem][1]*vals[n]);
}
*/
int main(){
    int budg, in;
    scanf("%d", &budg);
    if (budg==0){
        cout<<"-1\n";
        return 0;
    }
    for (int i=1;i<=9;i++){
        scanf("%d", &vals[i]);
    }
    string s = finder(budg);
    if (s.size()==0)
        cout<<"-1\n";
    else cout<<s<<endl;
}




#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int dp[10][1000010][2];
int vals[10];

int maximize(int n, int rem, int dd){
    //printf("%d %d\n", n ,rem);
    if (n==0){
        if (rem<=0)
            return 0;
        else{
            int f = 0;
            for (int i=1;i<=9;i++)
                if (vals[i]<=rem)
                    f = 1;
            if (f)
                return maximize(9, rem, 0);
            else return 0;
        }
    }
    if (dp[n][rem][0]!=-1)
        return dp[n][rem][0];
    if (dd)
        dp[n][rem][0] = maximize(n-1,rem, dd);
    else dp[n][rem][0] = 0;
    dp[n][rem][1] = 0;
    int num = rem/vals[n];
    int ret = num+maximize(n-1,rem%vals[n],dd);
    if (ret>=dp[n][rem][0]){
        dp[n][rem][0] = ret;
        dp[n][rem][1] = num;
    }
    return dp[n][rem][0];
}

string recur(int n, int rem, int dd){
    if (n==0){
        if (rem<=0)
            return "";
        else{
            int f = 0;
            for (int i=1;i<=9;i++)
                if (vals[i]<=rem)
                    f = 1;
            if (f)
                return recur(9, rem, 0);
            else return "";
        }
    }
    string ret (dp[n][rem][1],(char)('0'+n));
    string s1;
    if (dd)
        s1 = recur(n-1,dp[n][rem][1]>0?rem%vals[n]:rem, 1);
    else if (dp[n][rem][1]>0)
        s1 = recur(n-1,dp[n][rem][1]>0?rem%vals[n]:rem, 1);
    else s1 = "";
    if (s1.size()==0)
        return ret;
    else if (s1[0]-'0'<n)
        return ret + s1;
    else return s1+ret;
}

int main(){
    int budg, in;
    scanf("%d", &budg);
    for (int i=1;i<=9;i++){
        scanf("%d", &vals[i]);
    }
    memset(dp,-1,sizeof dp);
    int sz = maximize(9,budg,1);
    if (sz==0){
        cout<<"-1"<<endl;
    }
    else {
        cout<<recur(9,budg,1)<<endl;
    }
}

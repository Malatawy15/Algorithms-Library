#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

string s1, s2;
int i1, i2, l1, l2;

int check1(){
    return s1[i1]=='+'||s1[i1]=='-'?(((i1>0&&isdigit(s1[i1-1]))||i1+1>=l1||!isdigit(s1[i1+1]))):1;
}

int check2(){
    return s2[i2]=='+'||s2[i2]=='-'?(((i2>0&&isdigit(s2[i2-1]))||i2+1>=l2||!isdigit(s2[i2+1]))):1;
}

int parse_ints(){
    string ns1 = "", ns2="";
    int rv1 = 0, rv2 = 0, az1 = 1, az2 = 1;
    if (!isdigit(s1[i1]))
        rv1 = s1[i1]=='+'?0:1, i1++;
    if (!isdigit(s2[i2]))
        rv2 = s2[i2]=='+'?0:1, i2++;
    for (int i=i1;i<l1;i++){
        if (!isdigit(s1[i]))
            break;
        if (i>i1)
            i1++;
        ns1+=s1[i];
        if (s1[i]!='0')
        	az1 = 0;
    }
    for (int i=i2;i<l2;i++){
        if (!isdigit(s2[i]))
            break;
        if (i>i2)
            i2++;
        ns2+=s2[i];
        if (s2[i]!='0')
        	az2 = 0;
    }
    if (az1&&az2)
    	return 0;
    int nn1 = ns1.size(), nn2 = ns2.size();
    if (nn2>nn1){
        for (int i=nn1;i<nn2;i++)
            ns1 = '0'+ns1;
    }
    else if (nn2<nn1){
        for (int i=nn2;i<nn1;i++)
            ns2 = '0'+ns2;
    }
    if (rv1)
    	ns1 = '+'+ns1;
    else ns1 = '-'+ns1;
    if (rv2)
    	ns2 = '+'+ns2;
    else ns2 = '-'+ns2;
    return ns1.compare(ns2);
}

int parse(){
    l1 = s1.size(),l2 = s2.size();
    i1 = 0, i2 = 0;
    while(i1<l1&&i2<l2){
        s1[i1] = toupper(s1[i1]);
        s2[i2] = toupper(s2[i2]);
        if (!isdigit(s1[i1])&&!isdigit(s2[i2])&&check1()&&check2()){
            if (s1[i1]>s2[i2])
                return 1;
            else if (s1[i1]<s2[i2])
                return -1;
        }
        else if ((isdigit(s1[i1])||!check1())&&(isdigit(s2[i2])||!check2())){
            int x = parse_ints();
            if (x>0)
                return 1;
            else if (x<0)
                return -1;
        }
        else {
            if ((isdigit(s1[i1])||!check1())&&!(isdigit(s2[i2])||!check2()))
                return -1;
            else return 1;
        }
        i1++,i2++;
    }
    if (i1==l1&&i2==l2)
        return 0;
    else if (i1==l1&&i2!=l2)
        return -1;
    else if (i1!=l1&&i2==l2)
        return 1;
}

int main(){
    int t;
    cin>>t;
    for (int k=1;k<=t;k++){
        cin>>s1>>s2;
        printf("%d %d\n",k,parse());
    }
}

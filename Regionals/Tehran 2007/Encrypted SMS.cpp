#include<stdio.h>
#include<string.h>
#include<string>
#include<map>

using namespace std;

map<char,int> mp;
string nums[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int main(){
    char msg[500];
    string ans;
    gets(msg);
    mp.insert(make_pair('a',0));mp.insert(make_pair('b',0));mp.insert(make_pair('c',0));
    mp.insert(make_pair('d',1));mp.insert(make_pair('e',1));mp.insert(make_pair('f',1));
    mp.insert(make_pair('g',2));mp.insert(make_pair('h',2));mp.insert(make_pair('i',2));
    mp.insert(make_pair('j',3));mp.insert(make_pair('k',3));mp.insert(make_pair('l',3));
    mp.insert(make_pair('m',4));mp.insert(make_pair('n',4));mp.insert(make_pair('o',4));
    mp.insert(make_pair('p',5));mp.insert(make_pair('q',5));mp.insert(make_pair('r',5));mp.insert(make_pair('s',5));
    mp.insert(make_pair('t',6));mp.insert(make_pair('u',6));mp.insert(make_pair('v',6));
    mp.insert(make_pair('w',7));mp.insert(make_pair('x',7));mp.insert(make_pair('y',7));mp.insert(make_pair('z',7));
    while(msg[0]!='#'){
        ans = "";
        int size = strlen(msg);
        for (int i=0;i<size;i++){
            int f = 0;
            if (msg[i]>='A'&&msg[i]<='Z'){
                f = 1;
                msg[i]+=32;
            }
            int p = mp.find(msg[i])->second,off=0, x = nums[p].size();
            while (nums[p][off]!=msg[i])off++;
            for (int j=0;j<=i;j++) off = (off-1+x)%x;
            ans+=(f?nums[p][off]-32:nums[p][off]);
        }
        printf("%s\n",ans.c_str());
        gets(msg);
    }
}

#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    char s[100010];
    int vis [10];
    memset(vis, 0, sizeof vis);
    scanf("%s", s);
    int size = strlen(s), dis = 0, z = 0;
    long long prod = 1LL;
    for (int i =0;i<size;i++){
        if (s[i]=='?')
            if (i==0)
                prod*=9;
            else prod*=10;
        else if (s[i]>='A'&&s[i]<='J')
            if (!vis[s[i]-'A']){
                dis++;
                vis[s[i]-'A'] = 1;
                if (i==0)
                    z = 1;
            }
    }
    for (int i=0;i<dis;i++){
        prod*=(10-i);
    }
    if (z)
        prod = prod*9/10;
    printf("%I64d\n",prod);
}

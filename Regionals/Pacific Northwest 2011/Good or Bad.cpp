#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    char name[1000];
    int t;
    gets(name);
    sscanf(name,"%d",&t);
    while(t--){
        int a=0,b=0;
        gets(name);
        for (int i=0;i<strlen(name);i++)
            if (name[i]=='b'||name[i]=='B')
                b++;
            else if (name[i]=='g'||name[i]=='G')
                a++;
        if (a==b){
            printf("%s is NEUTRAL\n",name);
        }
        else if (a>b){
            printf("%s is GOOD\n",name);
        }
        else {
            printf("%s is A BADDY\n",name);
        }
    }
}

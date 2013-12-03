#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    char buf [2000];
    char op [2000];
    int a,b, cn = 1;
    bool ret;
    while(true){
        gets(buf);
        sscanf(buf,"%d %s %d", &a,op,&b);
        if (op[0]=='E')
            break;
        int size = strlen(op);
        if (size==1){
            if (op[0]=='>')
                ret = a>b;
            else if (op[0]=='<')
                ret = a<b;
        }
        else{
            if (op[0]=='>')
                ret = a>=b;
            else if (op[0]=='<')
                ret = a<=b;
            else if (op[0]=='=')
                ret = a==b;
            else if (op[0]=='!')
                ret = a!=b;
        }
        if (ret)
            printf("Case %d: true\n",cn++);
        else printf("Case %d: false\n",cn++);
    }
}

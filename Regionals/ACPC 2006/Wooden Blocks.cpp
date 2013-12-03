#include<stdio.h>
#include<string.h>

using namespace std;

char s[10010];

int check(){
    int size = strlen(s);
    if (size<=2)
        return 0;
    if (s[0]!='1')
        return 0;
    if (s[size-1]!='2')
        return 0;
    //int i=0,j=size-1;
    for (int i=0;i<size;i++){
        if (s[i]=='1'&&i!=0)
            return 0;
        if (s[i]=='2'&&i!=size-1)
            return 0;
        if (s[i]=='1'){
            if (s[i+1]!='4'&&s[i+1]!='5')
                return 0;
        }
        if (s[i]=='2'){
            if (s[i-1]!='6'&&s[i-1]!='4')
                return 0;
        }
        if (s[i]=='3'){
            if (s[i-1]!='6'&&s[i-1]!='4')
                return 0;
            if (s[i+1]!='5'&&s[i+1]!='4')
                return 0;
        }
        if (s[i]=='4'){
            if (s[i-1]!='1'&&s[i-1]!='3')
                return 0;
            if (s[i+1]!='2'&&s[i+1]!='3')
                return 0;
        }
        if (s[i]=='5'){
            if (s[i-1]!='1'&&s[i-1]!='3')
                return 0;
            if (s[i+1]!='8')
                return 0;
        }
        if (s[i]=='6'){
            if (s[i-1]!='8')
                return 0;
            if (s[i+1]!='2'&&s[i+1]!='3')
                return 0;
        }
        if (s[i]=='7'){
            if (s[i-1]!='8')
                return 0;
            if (s[i+1]!='8')
                return 0;
        }
        if (s[i]=='8'){
            if (s[i-1]!='5'&&s[i-1]!='7')
                return 0;
            if (s[i+1]!='6'&&s[i+1]!='7')
                return 0;
        }
    }
    int ss = 0;
    for (int i=0;i<size;i++){
        if (s[i]=='5')
            ss++;
        if (s[i]=='6')
            ss--;
        if (ss<0)
            return 0;
    }
    if (ss!=0)
        return 0;
    return 1;
}

int main(){
    int cn = 1;
    scanf("%s", s);
    while(s[0]!='0'){
        if (check()){
            printf("%d. VALID\n",cn++);
        }
        else {
            printf("%d. NOT\n", cn++);
        }
        scanf("%s", s);
    }
}

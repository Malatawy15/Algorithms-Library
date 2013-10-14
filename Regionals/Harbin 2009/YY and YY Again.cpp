#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char buf [200];
    while(gets(buf)!=NULL){
        int sum = 0;
        for (int i=0;i<strlen(buf);i++)
            if (buf[i]>='A'&&buf[i]<='Z')
                sum+=(buf[i]-'A'+1);
        if (sum>100)
            printf("INVALID\n");
        else printf("%d\n",sum);
    }
}

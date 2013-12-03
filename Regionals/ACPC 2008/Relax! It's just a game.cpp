#include <stdio.h>

using namespace std;

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    while(!(a==-1&&b==-1)){
        if (a==1||b==1){
            printf("%d+%d=%d\n",a,b,a+b);
        }
        else{
            printf("%d+%d!=%d\n",a,b,a+b);
        }
        scanf("%d %d", &a, &b);
    }
}

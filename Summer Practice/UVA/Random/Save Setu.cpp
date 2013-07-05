#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    int sum = 0, t, r;
    char str[100];
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        if (!strcmp(str,"donate")){
            scanf("%d", &r);
            sum+=r;
        }
        else printf("%d\n", sum);
    }
}

#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int fir = 0;
    int cnt [4];
    char buf[200];
    scanf("%s", buf);
    memset(cnt,0,sizeof cnt);
    for (int i=0;i<strlen(buf);i+=2){
        cnt[buf[i]-'0']++;
    }
    for (int i=1;i<=3;i++){
        for (int j=0;j<cnt[i];j++)
            if (fir)
                printf("+%d",i);
            else {
                fir = 1;
                printf("%d",i);
            }
    }
    printf("\n");
}

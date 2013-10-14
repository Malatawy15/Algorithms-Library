#include<stdio.h>
#include<string.h>

using namespace std;
char msg[10000000];
char map[26];
int main(){
    int t;
    scanf("%d", &t);
    gets(map);
    for (int k=1;k<=t;k++){
    	printf("%d ",k);
        gets(msg);
        gets(map);
        for (int i=0;i<strlen(msg);i++){
            if (msg[i]==' ')
                printf(" ");
            else printf("%c",map[msg[i]-'A']);
        }
        printf("\n");
    }
}

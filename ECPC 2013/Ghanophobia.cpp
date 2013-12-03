#include<stdio.h>

using namespace std;

int main(){
    freopen("ghanophobia.in", "r", stdin);
    int t, cn = 1;
    scanf("%d", &t);
    while(t--){
        int a,b;
        scanf("%d:%d", &a, &b);
        printf("Case %d: ", cn++);
        if (a==6&&b==1){
            printf("PENALTIES\n");
        }
        else if (b>=a||a-b<5){
            printf("NO\n");
        }
        else if (a-b>5){
            printf("YES\n");
        }
        else if (a==5&&b==0)
            printf("YES\n");
        else printf("NO\n");
    }
}

#include<stdio.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int f = 0, s = -1, p = -1, n;
        scanf("%d", &n);
        for (int i=0;i<n;i++){
            scanf("%d", &s);
            if (s==p)
                f = 1;
            p = s;
        }
        if (f)
            printf("boring\n");
        else printf("non-boring\n");
    }
}

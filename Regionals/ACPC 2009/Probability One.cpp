#include <stdio.h>

using namespace std;

int main(){
    int n,cs = 1;
    scanf("%d", &n);
    while(n){
        if (n%2)
            printf("%d. odd %d\n",cs++,(n-1)>>1);
        else printf("%d. even %d\n",cs++,n>>1);
        scanf("%d", &n);
    }
}

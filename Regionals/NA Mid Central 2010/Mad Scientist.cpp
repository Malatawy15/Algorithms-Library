#include<stdio.h>

using namespace std;

int main(){
    int K, l, m, n, f;
    scanf("%d", &K);
    while(K){
        l = 0;
        n = 1;
        f = 0;
        for (int i=0;i<K;i++){
            scanf("%d", &m);
            for (int j=0;j<m-l;j++){
                if (f)
                    printf(" %d",n);
                else {
                    f = 1;
                    printf("%d",n);
                }
            }
            l = m;
            n++;
        }
        printf("\n");
        scanf("%d", &K);
    }
}

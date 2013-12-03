#include <stdio.h>

using namespace std;

int main(){
    int n, k;
    while(scanf("%d %d", &n ,&k)>0){
        int sum = n, ne, u, tot = 0;
        while(sum>=k){
            ne = sum/k;
            u = (sum/k)*k;
            tot+=u;
            sum -= u;
            sum+=ne;
            //printf("%d %d %d %d\n", sum,u,ne,tot);
        }
        tot+=sum;
        printf("%d\n", tot);
    }
}

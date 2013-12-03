#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int t, c, n, maxi;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &c, &n);
        maxi = n;
        while(n!=1){
            if (n%2==0){
                n/=2;
            }
            else {
                n = 3*n+1;
                maxi = max(n,maxi);
            }
        }
        printf("%d %d\n", c, maxi);
    }
}

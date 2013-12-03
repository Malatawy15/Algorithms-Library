#include<stdio.h>

using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i=1;i<=n;i++)
        if (gcd(n,i)==1) sum++;
    printf("%d\n", sum);
}

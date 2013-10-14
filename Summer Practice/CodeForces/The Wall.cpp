#include <stdio.h>

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main(){
    int x,y,a,b;
    scanf("%d %d %d %d", &x,&y,&a,&b);
    int l = lcm(x,y);
    int n = b/l;
    int m = a/l;
    printf("%d\n", n-m+(a%l==0?1:0));
}

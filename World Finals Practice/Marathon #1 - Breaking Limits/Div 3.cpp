#include<stdio.h>

using namespace std;

int main(){
    int a;
    scanf("%d", &a);
    a--;
    int sum = a/3*2 + a%3;
    printf("%d\n",sum);
}

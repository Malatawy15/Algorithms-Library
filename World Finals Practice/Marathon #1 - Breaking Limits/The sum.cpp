#include<stdio.h>

using namespace std;

int main(){
    int a, lst1 = 1, lst2 = 1, sum = 0, nn;
    scanf("%d", &a);
    for (int i=1;i<=a;i++){
        if (i==1) sum+=1;
        else if (i==2) sum+=1;
        else{
            nn = lst1+lst2;
            sum+=(nn);
            lst1 = lst2;
            lst2 = nn;
        }
    }
    printf("%d\n",sum);
}

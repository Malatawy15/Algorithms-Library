#include <stdio.h>
#include <string.h>

using namespace std;

int N, T1, T2, T3;

int calc(int init){
    int sum = N<<1;
    if (init!=T1){
        if (init>T1)
            sum+=(init-T1);
        else sum+= (N-T1) + init;
    }
    init = T1;
    sum+=N;
    if (init!=T2){
        if (init<T2)
            sum+=(T2-init);
        else sum+= (N-init) + T2;

    }
    init = T2;
    if (init!=T3){
        if (init>T3)
            sum+=(init-T3);
        else sum+= (N-T3) + init;
    }
    return sum;
}

int main(){
    scanf("%d %d %d %d", &N, &T1, &T2, &T3);
    while(!(!N&&!T1&&!T2&&!T3)){
        int sum = 0;
        for (int i=0;i<N;i++)
            sum+=calc(i);
        printf("%.3lf\n",(sum*1.0)/N);
        scanf("%d %d %d %d", &N, &T1, &T2, &T3);
    }
}

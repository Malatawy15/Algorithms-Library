#include <stdio.h>

using namespace std;

int N;
int vals[1000001];

int sums(int si){
    if (vals[si]<0)
        return 0;
    int ni = (si+1)%N, sum = vals[si];
    while(ni!=si){
        sum+=vals[ni];
        if (sum<0)
            return 0;
        ni = (ni+1)%N;
    }
    return 1;
}

int main(){
    scanf("%d", &N);
    while(N){
        int sum = 0;
        for (int i=0;i<N;i++){
            scanf("%d", &vals[i]);
        }
        for (int i=0;i<N;i++)
            sum+=sums(i);
        scanf("%d", &N);
        printf("%d\n", sum);
    }
}

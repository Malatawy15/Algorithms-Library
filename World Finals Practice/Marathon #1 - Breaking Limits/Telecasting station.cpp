#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int N;
int vals [15010][2];

double calc(double pos){
    double sum = 0;
    for (int i=0;i<N;i++)
        sum += (fabs(pos-vals[i][0])*vals[i][1]);
    return sum;
}

double ternary(){
    double low = 0.0, high = 50000.0;
    for (int i=0;i<100;i++){
        //printf("%.5lf %.5lf\n",low,high);
        double third = low + ((high-low)/3.0);
        double two_thirds = (high - (high-low)/3.0);
        if (calc(third)-calc(two_thirds)>(1e-12)){
            low = third;
        }
        else high = two_thirds;
    }
    return (low+high)/2;
}

int main(){
    scanf("%d", &N);
    for (int i=0;i<N;i++)
        scanf("%d %d", &vals[i][0], &vals[i][1]);
    printf("%.5lf\n", ternary());
}

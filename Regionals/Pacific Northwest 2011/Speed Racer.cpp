#include<stdio.h>
#include<string.h>

using namespace std;

double a,b,c,d,m,t;

double eq(double v){
    return a*v*v*v+b*v*v+c*v;
}

double binary_search(){
    double low = 0, high = 1000.0;
    for (int i=0;i<100;i++){
        double mid = (low+high)/2;
        if (eq(mid)>t/m-d)
            high = mid;
        else low = mid;
    }
    return low;
}

int main(){
    while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&m,&t)>0){
        printf("%.2lf\n",((int)(binary_search()*100))/100.0);
    }
}

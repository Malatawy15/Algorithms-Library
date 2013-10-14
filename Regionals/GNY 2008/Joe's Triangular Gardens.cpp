#include <stdio.h>
#include <complex>
#include <math.h>

using namespace std;

int main(){
    complex<double> z1,z2,z3,ans1,ans2,a,b,avg;
    double x,y,rl,rl1;
    int t;
    scanf("%d", &t);
    for (int k=1;k<=t;k++){
        scanf("%lf %lf",&x,&y);
    z1 = complex<double>(x,y);
    scanf("%lf %lf",&x,&y);
    z2 = complex<double>(x,y);
    scanf("%lf %lf",&x,&y);
    z3 = complex<double>(x,y);
    a = z1+z2+z3;
    b = (z1*z2)+(z1*z3)+(z2*z3);
    ans1 = ((1.0/3.0)*a)+sqrt((1.0/9.0)*a*a-b/3.0);
    ans2 = ((1.0/3.0)*a)-sqrt((1.0/9.0)*a*a-b/3.0);
    double x1 = floor(ans1.real()* 100 + 0.5) / 100;
    double y1 = floor(ans1.imag()* 100 + 0.5) / 100;
    double x2 = floor(ans2.real()* 100 + 0.5) / 100;
    double y2 = floor(ans2.imag()* 100 + 0.5) / 100;

    avg = complex<double>(z2.real()+((z1.real()-z2.real())/2.0),z2.imag()+((z1.imag()-z2.imag())/2.0));
    rl = sqrt((avg.real()-ans1.real())*(avg.real()-ans1.real())+(avg.imag()-ans1.imag())*(avg.imag()-ans1.imag()))+ sqrt((avg.real()-ans2.real())*(avg.real()-ans2.real())+(avg.imag()-ans2.imag())*(avg.imag()-ans2.imag()));
    avg = complex<double>(z3.real()+((z1.real()-z3.real())/2.0),z3.imag()+((z1.imag()-z3.imag())/2.0));
    rl1 = sqrt((avg.real()-ans1.real())*(avg.real()-ans1.real())+(avg.imag()-ans1.imag())*(avg.imag()-ans1.imag()))+ sqrt((avg.real()-ans2.real())*(avg.real()-ans2.real())+(avg.imag()-ans2.imag())*(avg.imag()-ans2.imag()));
    rl = max(rl,rl1);
    avg = complex<double>(z3.real()+((z2.real()-z3.real())/2.0),z3.imag()+((z2.imag()-z3.imag())/2.0));
    rl1 = sqrt((avg.real()-ans1.real())*(avg.real()-ans1.real())+(avg.imag()-ans1.imag())*(avg.imag()-ans1.imag()))+ sqrt((avg.real()-ans2.real())*(avg.real()-ans2.real())+(avg.imag()-ans2.imag())*(avg.imag()-ans2.imag()));
    rl = max(rl,rl1);
    if (x1>x2){
        double tmp = x1;
        x1 = x2;
        x2 = tmp;
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    else if (fabs(x1-x2)<=(1e-9)&&y1>y2){
        double tmp = x1;
        x1 = x2;
        x2 = tmp;
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    printf("%d %.2lf %.2lf %.2lf %.2lf %.2lf\n",k,x1, y1, x2, y2, rl);
    }
}

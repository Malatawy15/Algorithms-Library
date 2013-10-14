#include <stdio.h>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
#define point complex<double>
#define vec(a,b)  ((b)-(a))
#define X real()
#define Y imag()
#define dot(A,B) ((A.X*B.X) + (A.Y*B.Y))
#define cross(A,B) ((A.X*B.Y) - (A.Y*B.X))
#define error point(-1234.5678,-8765.4321)
#define EPS (1e-9)

double areaPolygon (point p [], int N){
    double area = 0.0;
    for (int i = 1;i<N-1;i++){
        point p1 = vec(p[0],p[i]);
        point p2 = vec(p[0],p[i+1]);
        area += cross(p1,p2);
    }
    return abs(area/2.0);
}

double angle(point p1, point p2){
    return acos((dot(p1,p2))/(abs(p1)*abs(p2)));
}

point A,B,C,D,E,F;

int main(){
    double rx, ry;
    scanf("%lf %lf", &rx, &ry);
    A = point(rx,ry);
    scanf("%lf %lf", &rx, &ry);
    B = point(rx,ry);
    scanf("%lf %lf", &rx, &ry);
    C = point(rx,ry);
    scanf("%lf %lf", &rx, &ry);
    D = point(rx,ry);
    scanf("%lf %lf", &rx, &ry);
    E = point(rx,ry);
    scanf("%lf %lf", &rx, &ry);
    F = point(rx,ry);
    while(!(A.X<=EPS&&B.X<=EPS&&C.X<=EPS&&D.X<=EPS&&E.X<=EPS&&F.X<=EPS&&A.Y<=EPS&&B.Y<=EPS&&C.Y<=EPS&&D.Y<=EPS&&E.Y<=EPS&&F.Y<=EPS)){
        double a = hypot(fabs(D.X-E.X),fabs(D.Y-E.Y)),b = hypot(fabs(F.X-E.X),fabs(F.Y-E.Y)),c = hypot(fabs(D.X-F.X),fabs(D.Y-F.Y)), s = (a+b+c)/2, tri = sqrt(s*(s-a)*(s-b)*(s-c));
        point pp1 = vec(A,B), pp2 = vec(A,C);
        double hp = tri/abs(pp1);
        double Hi = hp/(sin(angle(pp1,pp2)));
        point H = A+Hi*(pp2/abs(pp2));
        point G = H+abs(pp1)*(pp1/abs(pp1));
        printf("%.3lf %.3lf %.3lf %.3lf\n", G.X, G.Y, H.X, H.Y);
        scanf("%lf %lf", &rx, &ry);
        A = point(rx,ry);
        scanf("%lf %lf", &rx, &ry);
        B = point(rx,ry);
        scanf("%lf %lf", &rx, &ry);
        C = point(rx,ry);
        scanf("%lf %lf", &rx, &ry);
        D = point(rx,ry);
        scanf("%lf %lf", &rx, &ry);
        E = point(rx,ry);
        scanf("%lf %lf", &rx, &ry);
        F = point(rx,ry);
    }
}

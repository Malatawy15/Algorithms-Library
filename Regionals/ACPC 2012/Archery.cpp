#include <vector>
#include <stdio.h>
#include <complex>
#include <algorithm>
#include <math.h>
using namespace std;
#define point complex<double>
#define vec(a,b)  ((b)-(a))
#define X real()
#define Y imag()
#define dot(A,B) ((A.X*B.X) + (A.Y*B.Y))
#define cross(A,B) ((A.X*B.Y) - (A.Y*B.X))
#define error point(-1234.5678,-8765.4321)

double get_angle(double x, double y){
    point p1 = vec(point(0,0),point(x,y)), p2 = vec(point(0,0),point(1,0));
    printf("%lf %lf\n", acos(dot(p1,p2)/abs(p1)), atan(y/x));
    return acos(dot(p1,p2)/abs(p1));
    //return atan2(y,x);
}

const double pi = 2*acos(-1);

int main(){
    int t, N;
    double x,y;
    scanf("%d", &t);
    vector<pair<double,int> > angles;
    while(t--){
        angles.clear();
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%lf %lf",&x,&y);
            double ang1 = get_angle(x,y);
            scanf("%lf %lf",&x,&y);
            double ang2 = get_angle(x,y);
            //printf("ANGLES: %lf %lf\n",ang1,ang2);
            angles.push_back(make_pair(min(ang1,ang2),1));
            angles.push_back(make_pair(max(ang1,ang2),0));
        }
        int cnt = 0;
        double la = 0.0, sum = 0.0;
        sort(angles.begin(), angles.end());
        for (int i=0;i<angles.size();i++){
            //printf("%lf %lf %lf\n",angles[0].first,(angles[0].first-la),((angles[0].first-la)*cnt*1.0/360.0));
            sum+=((angles[i].first-la)*cnt);
            la = angles[i].first;
            if (angles[i].second){
                cnt++;
            }
            else {
                cnt--;
            }
        }
        printf("%.5lf\n", sum/pi);
    }
}

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


double distance (point p){
    return sqrt(p.X*p.X+p.Y*p.Y);
}

double linePointDis (point p1,point p2, point p3){
    return abs(cross(vec(p1,p2),vec(p1,p3))/distance(vec(p1,p2)));
}

double areaPolygon (point p [], int N){
    double area = 0.0;
    for (int i = 1;i<N-1;i++){
        point p1 = vec(p[0],p[i]);
        point p2 = vec(p[0],p[i+1]);
        area += cross(p1,p2);
    }
    return abs(area/2.0);
}

point centerOfMass (point p [], int N){
    double A = areaPolygon(p,N)*3.0,Cx = 0.0,Cy =0.0;
    for (int i=0;i<N-1;i++){
			Cx+=((p[i].X+p[i+1].X)*(p[i].X*p[i+1].Y-p[i].Y*p[i+1].X));
		}
		Cx+=((p[N-1].X+p[0].X)*(p[N-1].X*p[0].Y-p[N-1].Y*p[0].X));
		Cx/=A;
		for (int i=0;i<N-1;i++){
			Cy+=((p[i].Y+p[i+1].Y)*(p[i].X*p[i+1].Y-p[i].Y*p[i+1].X));
		}
		Cy+=((p[N-1].Y+p[0].Y)*(p[N-1].X*p[0].Y-p[N-1].Y*p[0].X));
		Cy/=A;
		return point (Cx,Cy);
}

int linesIntersection (point p1,point p2,point p3,point p4,point &res){
    double A1 = p2.Y-p1.Y;
    double B1 = p1.X-p2.X;
    double C1 = A1*p1.X+B1*p1.Y;
    double A2 = p4.Y-p3.Y;
    double B2 = p3.X-p4.X;
    double C2 = A2*p3.X+B2*p3.Y;
    double det = A1*B2 - A2*B1;
    if(det == 0){
        return 0;
    }else{
        res = point((B2*C1 - B1*C2)/det,(A1*C2 - A2*C1)/det);
        return 1;
    }
}

point midPoint (point p1,point p2){
    return point ((p1.X+p2.X)/2,(p1.Y+p2.Y)/2);
}

void circleThreePoints (point p1,point p2,point p3,point &cen, double &rad){
    double A1 = p2.Y-p1.Y;
    double B1 = p1.X-p2.X;
    double C1 = A1*p1.X+B1*p1.Y;
    double A2 = p2.Y-p3.Y;
    double B2 = p3.X-p2.X;
    double C2 = A2*p3.X+B2*p3.Y;
    point m1 = midPoint(p1,p2);
    point m2 = midPoint(p2,p3);
    double D1 = -B1*m1.X+A1*m1.Y;
    double D2 = -B2*m2.X+A2*m2.Y;
    point po1 = point(m1.X+1,(D1+B1*(m1.X+1))/A1);
    point po2 = point(m2.X+1,(D2+B2*(m2.X+1))/A2);
    point res;
    linesIntersection(m1,po1,m2,po2,res);
    rad = sqrt((cen.X-p1.X)*(cen.X-p1.X)+(cen.Y-p1.Y)*(cen.Y-p1.Y));
}


vector<point> convexHull(point pts [],int N){
    int p = 0;
    //First find the leftmost point
    for(int i = 1; i<N; i++){
        if(pts[i].X < pts[p].X)
            p = i;
        else if (pts[i].X == pts[p].X)
            if (pts[i].Y>pts[p].Y)
                p = i;
    }
    vector <point> v;
    v.push_back(p);
    int start = p;
    do{
        int n = -1;
        for(int i = 0; i<N; i++){
            //Don't go back to the same point you came from
            if(i == p)continue;
            //If there is no N yet, set it to i
            if(n == -1)n = i;
            double cross = cross((pts[i] - pts[p]),(pts[n] - pts[p]));
            if(cross < 0){
            //As described above, set N=X
                n = i;
            }
        }
        p = n;
        v.push_back(p);
    }while(start!=p);
}


int main (){
    point p [4];
    //point p1 (2.0,2.0);
    //point p2 (4.0,4.0);
    //point p3 = vec(p1,p2);
    //printf("%f %f",p3.X,p3.Y);
    p[0] = point(0.0,0.0);
    p[1] = point(4.0,0.0);
    p[3] = point(0.0,4.0);
    p[2] = point(4.0,4.0);
    point p5;
    point a(1.0,2.0);
    point b(2.0,1.0);
    point c(1.0,0.0);
    point cen;
    double rad;
    circleThreePoints(a,b,c,cen,rad);
    printf("%f %f %f\n",cen.X,cen.Y,rad);
    int x =  linesIntersection(p[0],p[2],p[1],p[3],p5);
    if (x){
        printf("Points: %f %f\n",p5.X,p5.Y);
    }
    else printf("None\n");
    printf("%f\n",areaPolygon(p,4));
}

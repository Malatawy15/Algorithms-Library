#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
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

int cn,sx,sy,ex,ey,w,h,nl;
short vis[65][65][65][2][65][2];
point lines[6][2];

int col(point a, point b, point c){
    if (c==a||c==b)
        return 1;
    else return fabs(cross(vec(a,b),vec(a,c)))<EPS;
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

struct state{
    int x,y,ax,ay,steps,xd,yd;
    state(int xx, int yy, int axx, int ayy, int xdd, int ydd, int st){
        x = xx;
        y = yy;
        ax = axx;
        ay = ayy;
        steps = st;
        xd = xdd;
        yd = ydd;
    }
};

int is_valid(int x1, int y1, int x2, int y2){
    point p1(x1,y1), p2(x2,y2), p3;
    for (int i=0;i<nl;i++){
        if (linesIntersection(p1,p2,lines[i][0],lines[i][1],p3)){
            if (p3.X>=min(lines[i][0].X,lines[i][1].X)&&p3.X<=max(lines[i][0].X,lines[i][1].X))
                return 0;
        }
    }
    return 1;
}

int bfs(){
    queue<state>q;
    q.push(state(sx,sy,0,0,0,0,0));
    vis[sx][sy][0][0][0][0] = cn;
    while(!q.empty()){
        state s = q.front();
        q.pop();
        int nax1=s.x+1, nax2=s.x-1, nay1=s.y+1, nay2=s.y-1;
        if (s.x==0){
            q.push(state(s.x,s.y,1,s.y,1,s.yd,s.steps+1));
            q.push(state(s.x,s.y,1,s.y,0,s.yd,s.steps+1));
        }
        else {
            if (s.ax<w)
                q.push(state(s.x,s.y,s.ax+1,s.y,s.xd,s.yd,s.steps+1));
            q.push(state(s.x,s.y,s.ax-1,s.y,s.ax-1==0?0:s.xd,s.yd,s.steps+1));
        }
        if (s.y==0){
            q.push(state(s.x,s.y,s.x,1,s.xd,0,s.steps+1));
            q.push(state(s.x,s.y,s.x,1,s.xd,1,s.steps+1));
        }
        else {}
        //for ()
    }
}

int main(){
}

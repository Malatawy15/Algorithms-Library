#include<stdio.h>
#include<string>
#include<string>
#include<map>
#include<math.h>

using namespace std;

const double pi = acos(-1);
const long long inf = 100000000000000LL;

int N,M,Q;
double pos [101][2];
long long matrix [101][101];
map<string, int> mp;
char buf[25];

double dtr(double d){
	return d*pi/180.0;
}

long long calc_dis(double d1,double g1,double d2,double g2){
    return (long long)(round(6378*acos(cos(d1)*cos(d2)*cos(g1-g2)+sin(d1)*sin(d2))));
}

void init(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            matrix [i][j] = inf;
        }
    }
}

void floyd_warshall(){
    for (int k=0;k<N;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                matrix [i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }
}

int main(){
    double x,y;
    int f, t, c = 1, flag = 0;
    scanf("%d %d %d",&N,&M,&Q);
    while(!(!N&&!M&&!Q)){
        init();
        mp.clear();
        for (int i=0;i<N;i++){
            scanf("%s %lf %lf", buf, &x, &y);
            mp.insert(make_pair(string(buf),i));
            pos [i][0] = dtr(x);
            pos [i][1] = dtr(y);
        }
        for (int i=0;i<M;i++){
            scanf("%s", buf);
            f = mp.find(string(buf))->second;
            scanf("%s", buf);
            t = mp.find(string(buf))->second;
            matrix [f][t] = calc_dis(pos [f][0], pos [f][1], pos [t][0], pos [t][1]);
        }
        floyd_warshall();
        if (flag)
        	printf("\n");
        else flag = 1;
        printf("Case #%d\n", c++);
        for (int i=0;i<Q;i++){
            scanf("%s", buf);
            f = mp.find(string(buf))->second;
            scanf("%s", buf);
            t = mp.find(string(buf))->second;
            if (matrix [f][t]<inf)
                printf("%lld km\n",matrix [f][t]);
            else printf("no route exists\n");
        }
        scanf("%d %d %d",&N,&M,&Q);
    }
}

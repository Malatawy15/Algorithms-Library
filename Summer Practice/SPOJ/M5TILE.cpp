#include <iostream>
#include <string.h>
using namespace std;int j=-1;typedef long long Y;Y d[50][20][20];Y f(int c, int b, int e){Y p=-1,&r=d[c][b][e];if(c==0)return b==1||b==7||b==4?1:0;if(r!=-1)return r;if(b==7)return f(c-1,e,0);r=0;while(++p<3)if(!(b&(1<<p)))break;if (!(e&(1<<p)))r+=f(c,(b|(1<<p)),(e|(1<<p)));if (p<2&&!(b&(1<<p+1)))r+=f(c,b|(1<<p)|(1<<p+1),e);return r;}int main(){memset(d,-1,sizeof d);while(++j<17)cout<<f(j,0,0)<<endl;}

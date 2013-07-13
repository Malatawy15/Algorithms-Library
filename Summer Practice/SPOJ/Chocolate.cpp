#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
    int hor[1000];
    int ver[1000];
    int t,N,M,ih,iv,hp,vp,sum,tmp,tmp1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&M,&N);
        for (int i=0;i<M-1;i++)
            scanf("%d",&hor[i]);
        for (int i=0;i<N-1;i++)
            scanf("%d",&ver[i]);
        sort(hor,hor+M-1);
        sort(ver,ver+N-1);
        ih = M-2;
        iv = N-2;
        hp = 1;
        vp = 1;
        sum = 0;
        while(1){
            if (ih<0&&iv<0)
                break;
            if (ih<0){
                while(iv>=0)
                    sum+=(hp*ver[iv--]);
                break;
            }
            if (iv<0){
                while(ih>=0)
                    sum+=(vp*hor[ih--]);
                break;
            }
            tmp = hor[ih]*vp+ver[iv]*(hp+1);
            tmp1 = ver[iv]*hp+hor[ih]*(vp+1);
            if (tmp==tmp1){
                if (M<N){
                    sum+=hor[ih--]*vp;
                    hp++;
                }
                else{
                    sum+=ver[iv--]*hp;
                    vp++;
                }
            }
            else if (tmp>tmp1){
                sum+=ver[iv--]*hp;
                vp++;
            }
            else{
                sum+=hor[ih--]*vp;
                hp++;
            }
        }
        printf("%d\n",sum);
    }
}

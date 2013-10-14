#include<stdio.h>

using namespace std;

int main(){
    int n, in;
    scanf("%d", &n);
    int tf = 0, f = 0, h = 0, can = 1;
    for (int i=0;i<n;i++){
        scanf("%d", &in);
        if (in ==100){
            h++;
            if (f>0&&tf>0){
                f--;tf--;
            }
            else if (tf>=3){
                tf-=3;
            }
            else{
              can = 0; break;
            }
        }
        else if (in==50){
            if (tf>0)tf--;
            else{
              can = 0; break;
            }
            f++;
        }
        else tf++;
    }
    if (can)
        printf("YES\n");
    else printf("NO\n");
}

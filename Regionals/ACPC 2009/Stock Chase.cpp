#include <stdio.h>
#include <string.h>
#include <bitset>

using namespace std;

int N, T;

int main(){
    int x,y, cs = 1, cnt;
    scanf("%d %d", &N, &T);
    while(!(!N&&!T)){
        bitset<250> cont[N];
        cnt = 0;
        for (int i=0;i<N;i++)
            cont[i][i] = 1;
        for (int i=0;i<T;i++){
            scanf("%d %d", &x, &y);
            x--;y--;
            int f = 1;
            for (int i=0;i<N;i++){
                if (cont[i][x]){
                    if (cont[y][i]){
                        f = 0;
                        break;
                    }
                }
            }
            if (!f){
                cnt++;
            }
            else{
                for (int j=0;j<N;j++)
                    if (cont[j][x])
                        cont[j]|=cont[y];
            }
        }
        printf("%d. %d\n", cs++, cnt);
        scanf("%d %d", &N, &T);
    }
}

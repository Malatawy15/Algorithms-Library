#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

int dp[5][4][4100][120];
short vis[5][4][4100][120];

int max_bit, L, N, init_mask;
short cn;

int counter(int x, int y, int bitmask, int l){
    //printf("%d %d %d %d\n",x,y,bitmask,l);
    int ind = 3*x+y;
    if (l==L)
        return 1;
    if (l>L||l>40)
        return 0;
    if (bitmask==max_bit){
        return 0;
    }
    if (vis[x][y][bitmask][l]==cn)
        return dp[x][y][bitmask][l];
    dp[x][y][bitmask][l] = 0;
    vis[x][y][bitmask][l] = cn;
    for (int i=0;i<4;i++)
    for (int j=0;j<3;j++){
        int i1 = i*3+j;
        if ((bitmask&(1<<i1))==0){
            //printf("GOTO: %d %d %d %d\n",x,y,i,j);
            if (y==j){
                int f = 0;
                for (int k=min(x,i)+1;k<max(x,i);k++){
                    if ((bitmask&(1<<(k*3+j)))==0||(init_mask&(1<<(k*3+j)))!=0){
                        f = 1;
                        break;
                    }
                }
                if (f)
                    continue;
            }
            if (x==i){
                int f = 0;
                for (int k=min(y,j)+1;k<max(y,j);k++){
                    if ((bitmask&(1<<(x*3+k)))==0||(init_mask&(1<<(x*3+k)))!=0){
                        f = 1;
                        break;
                    }
                }
                if (f)
                    continue;
            }
            if (abs(x-i)==abs(y-j)&&abs(y-j)>1){
//                printf("FOUND!: %d %d %d %d %d\n",((bitmask&(1<<((x+1)*3+(y-1))))==0||(init_mask&(1<<((x+1)*3+(y-1))))==1),(bitmask&(1<<((x+1)*3+(y-1)))),(init_mask&(1<<((x+1)*3+(y-1)))),bitmask,init_bitmask);
                if (x<i&&y<j){
                    if ((bitmask&(1<<((x+1)*3+(y+1))))==0||(init_mask&(1<<((x+1)*3+(y+1))))!=0)
                        continue;
                }
                else if (i<x&&j<y){
                    if ((bitmask&(1<<((i+1)*3+(j+1))))==0||(init_mask&(1<<((i+1)*3+(j+1))))!=0)
                        continue;
                }
                else if (x<i&&j<y){
                    if ((bitmask&(1<<((x+1)*3+(y-1))))==0||(init_mask&(1<<((x+1)*3+(y-1))))!=0){
                        continue;
                    }
                }
                else if (i<x&&y<j){
                    if ((bitmask&(1<<((i+1)*3+(j-1))))==0||(init_mask&(1<<((i+1)*3+(j-1))))!=0)
                        continue;
                }
            }
            dp[x][y][bitmask][l] += counter(i,j,bitmask|(1<<i1),l+abs(x-i)+abs(y-j));
        }
    }
    return dp[x][y][bitmask][l];
}

int main(){
    int t,x,y;
    scanf("%d", &t);
    cn = 1;
    max_bit = (1<<12)-1;
    init_mask = 0;
    while(t--){
        init_mask = 0;
        scanf("%d %d", &L, &N);
        for (int i=0;i<N;i++){
            scanf("%d %d", &y, &x);
            y--;x--;
            init_mask|=(1<<(x*3+y));
        }
        int cnt = 0;
        for (int i=0;i<4;i++)
        for (int j=0;j<3;j++){
            int i1 = i*3+j;
            if ((init_mask&(1<<i1))==0){
                cnt += counter(i,j,init_mask|(1<<i1),0);
                cn++;
            }
        }
        if (cnt==0){
            printf("BAD MEMORY\n");
        }
        else printf("%d\n", cnt);
    }
}

/*
5
6 9
1 1
2 1
3 1
1 2
2 2
1 3
3 3
2 4
3 4
6 9
1 1
2 1
1 2
3 2
2 3
3 3
1 4
2 4
3 4
6 9
1 1
2 1
3 1
2 2
3 2
1 3
3 3
1 4
2 4
1 9
1 1
2 1
3 1
1 2
2 2
3 2
1 3
2 3
3 3
4 10
1 1
2 1
3 1
1 2
2 2
1 3
2 3
3 3
2 4
3 4
*/

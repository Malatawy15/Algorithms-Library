#include<stdio.h>
#include<string.h>
#include<bitset>
#include<algorithm>

using namespace std;

int N;
char grid[101][101];


int recur(int r, int c, bitset<101> rs, bitset<101> cs){
    //printf("Call:%d %d\n",r,c);
    if (r==N-1&&c==N-1)
        return grid[r][c]!='X'&&!rs[r]&&!cs[c];
    if (grid[r][c]=='X'){
        rs[r] = 0;cs[c] = 0;
        if (c==N-1)
            return recur(r+1,0,rs,cs);
        else return recur(r,c+1,rs,cs);
    }
    else {
        if (c==N-1){
            if (!rs[r]&&!cs[c]){
                int n1 = recur(r+1,0,rs,cs);
                rs[r] = 1;cs[c] = 1;
                int n2 = 1+recur(r+1,0,rs,cs);
                return max(n1,n2);
            }
            else return recur(r+1,0,rs,cs);
        }
        else {
            if (!rs[r]&&!cs[c]){
                int n1 = recur(r,c+1,rs,cs);
                rs[r] = 1;cs[c] = 1;
                int n2 = 1+recur(r,c+1,rs,cs);
                return max(n1,n2);
            }
            else return recur(r,c+1,rs,cs);
        }
    }
}

/*
int maximize(){
    int mc =0, mr=0;
    bitset<101> b;
    b.reset();
    for (int i=0;i<N;i++){
        int cnM=1000, cnI;
        for (int j=0;j<N;j++){
            if (grid[j][i]=='X'){
                b[j] = 0;
                if (cnM<1000){
                    mc++;
                    b[cnI] = 1;
                    cnM = 1000;
                }
            }
            else if (b[j])
                continue;
            else {
                int pos;
                for (int k=i+1;k<N;k++){
                    if (grid[j][k]=='X'){
                        pos = k;
                        break;
                    }
                    else if (k==N-1)
                        pos = N;
                }
                if (pos<cnM){
                    cnM = pos;
                    cnI = j;
                }
            }
        }
        if (cnM<1000){
            mc++;
            b[cnI] = 1;
        }
    }
    b.reset();
    for (int i=0;i<N;i++){
        int cnM=1000, cnI;
        for (int j=0;j<N;j++){
            if (grid[i][j]=='X'){
                b[j] = 0;
                if (cnM<1000){
                    mr++;
                    b[cnI] = 1;
                    cnM = 1000;
                }
            }
            else if (b[j])
                continue;
            else {
                int pos;
                for (int k=i+1;k<N;k++){
                    if (grid[k][j]=='X'){
                        pos = k;
                        break;
                    }
                    else if (k==N-1)
                        pos = N;
                }
                if (pos<cnM){
                    cnM = pos;
                    cnI = j;
                }
            }
        }
        if (cnM<1000){
            mr++;
            b[cnI] = 1;
        }
    }
    return max(mc,mr);
}
*/
int main(){
    while(scanf("%d", &N)>0){
        for (int i=0;i<N;i++)
            scanf("%s", grid[i]);
        bitset<101> rs,cs;
        rs.reset();
        cs.reset();
        printf("%d\n", recur(0,0,rs,cs));
    }
}

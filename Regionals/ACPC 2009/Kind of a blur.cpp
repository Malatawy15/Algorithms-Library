#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX_N 103                              // adjust this value as needed
struct AugmentedMatrix { double mat[MAX_N][MAX_N + 1]; };
struct ColumnVector { double vec[MAX_N]; };

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug) {
  // input: N, Augmented Matrix Aug, output: Column vector X, the answer
  int i, j, k, l; double t;

  for (i = 0; i < N - 1; i++) {            // the forward elimination phase
    l = i;
    for (j = i + 1; j < N; j++)       // which row has largest column value
      if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
        l = j;                                       // remember this row l
    // swap this pivot row, reason: minimize floating point error
    for (k = i; k <= N; k++)            // t is a temporary double variable
      t = Aug.mat[i][k], Aug.mat[i][k] = Aug.mat[l][k], Aug.mat[l][k] = t;
    for (j = i + 1; j < N; j++)     // the actual forward elimination phase
      for (k = N; k >= i; k--)
        Aug.mat[j][k] -= Aug.mat[i][k] * Aug.mat[j][i] / Aug.mat[i][i];
  }

  ColumnVector Ans;                          // the back substitution phase
  for (j = N - 1; j >= 0; j--) {                         // start from back
    for (t = 0.0, k = j + 1; k < N; k++) t += Aug.mat[j][k] * Ans.vec[k];
    Ans.vec[j] = (Aug.mat[j][N] - t) / Aug.mat[j][j]; // the answer is here
  }
  return Ans;
}


int main(){
    int f = 0, W, H, D;
    scanf("%d %d %d", &W, &H, &D);
    while(!(!W&&!H&&!D)){
        if (f)
            printf("\n");
        else f = 1;
        double grid [H][W];
        for (int i=0;i<H;i++)
            for (int j=0;j<W;j++)
                scanf("%lf", &grid[i][j]);
        AugmentedMatrix mat;
        int mx = H*W;
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                int cur = i*W+j, num = 0;
                for (int x=0;x<H;x++){
                    for (int y=0;y<W;y++){
                        if (abs(i-x)+abs(j-y)<=D){
                            num++;
                            mat.mat[cur][x*W+y] = 1;
                        }
                        else mat.mat[cur][x*W+y] = 0;
                    }
                }
                mat.mat[cur][mx] = grid[i][j]*num;
            }
        }
        /*
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                for (int k=0;k<H*W+1;k++)
                    printf("%8.2lf",mat.mat[i*W+j][k]);
                printf("\n");
            }
        }*/
        ColumnVector cv = GaussianElimination(W*H,mat);
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++)
                printf("%8.2lf",cv.vec[i*W+j]);
            printf("\n");
        }
        scanf("%d %d %d", &W, &H, &D);
    }
}

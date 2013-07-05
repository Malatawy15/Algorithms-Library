#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int x = n-1;
    int y = n*x;
    y/=2;
    if (n==4){
        printf("-1\n");
    }
    else{
        int arr[n][n];
        memset(arr,0,sizeof arr);
        for (int i=0;i<n;i++){
            for (int j = 2;j<=n;j+=2){
                arr[i][(i+j)%n] = 1;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
            if (j==n-1)
                printf("%d",arr[i][j]);
                else printf("%d ",arr[i][j]);
            printf("\n");
        }
    }
}

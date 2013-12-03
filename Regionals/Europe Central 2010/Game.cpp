#include<stdio.h>
#include<string.h>

using namespace std;

int a, b;
char grid[6][6];

void check(){
    for (int i=0;i<5;i++){
        for (int j=0;j<3;j++){
            if (grid[i][j]==grid[i][j+1]&&grid[i][j]==grid[i][j+2]){
                if (grid[i][j]=='A')
                    a = 1;
                else b = 1;
            }
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<5;j++){
            if (grid[i][j]==grid[i+1][j]&&grid[i][j]==grid[i+2][j]){
                if (grid[i][j]=='A')
                    a = 1;
                else b = 1;
            }
        }
    }
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            if (grid[i][j]==grid[i+1][j+1]&&grid[i][j]==grid[i+2][j+2])
                if (grid[i][j]=='A')
                    a = 1;
                else b = 1;
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            if (grid[i][j]==grid[i+1][j-1]&&grid[i][j]==grid[i+2][j-2])
                if (grid[i][j]=='A')
                    a = 1;
                else b = 1;

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for (int i=0;i<5;i++)
            scanf("%s", grid[i]);
        a = 0, b = 0;
        check();
        if (a&&b) printf("draw\n");
        else if (a) printf("A wins\n");
        else printf("B wins\n");
    }
}

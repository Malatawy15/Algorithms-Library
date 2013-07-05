/*
ID: malataw1
PROG: transform
LANG: C++
*/

#include<stdio.h>

using namespace std;

int N;
char newp[11][11];

int deg_90 (char oldp[11][11]){
    char trans[11][11];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            trans[j][N-i-1] = oldp[i][j];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (trans[i][j]!=newp[i][j])
                return 0;
    return 1;
}
int deg_180 (char oldp[11][11]){
    char trans[11][11];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            trans[N-i-1][N-j-1] = oldp[i][j];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (trans[i][j]!=newp[i][j])
                return 0;
    return 1;
}
int deg_270 (char oldp[11][11]){
    char trans[11][11];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            trans[N-j-1][i] = oldp[i][j];
    /*printf("\n\nStart:\n");
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            printf("%c", trans[i][j]);
        printf("\n");
    }*/
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (trans[i][j]!=newp[i][j])
                return 0;
    return 1;
}
int reflect(char oldp[11][11]){
    char trans[11][11];
    for (int i=0;i<N>>1;i++)
        for (int j=0;j<N;j++)
            trans[j][N-i-1] = oldp[i][j];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (trans[i][j]!=newp[i][j])
                return 0;
    return 1;
}
int reflect1(char oldp[11][11]){
    char trans[11][11];
    for (int i=0;i<N>>1;i++)
        for (int j=0;j<N;j++)
            trans[j][i] = oldp[j][N-i-1];
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (trans[i][j]!=newp[i][j])
                return 0;
    return 1;
}
int combine(char oldp[11][11]){
    char trans[11][11];
    for (int i=0;i<N>>1;i++)
        for (int j=0;j<N;j++)
            trans[N-i-1][j] = oldp[i][j];
    return deg_90(trans)||deg_180(trans)||deg_270(trans);
}
int no_change(char oldp[11][11]){
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (oldp[i][j]!=newp[i][j])
                return 0;
    return 1;
}

int main(){
    //freopen("transform.in", "r", stdin);
    //freopen("transform.out", "w", stdout);
    scanf("%d", &N);
    char oldp[11][11];
    for (int i=0;i<N;i++)
        scanf("%s", oldp[i]);
    for (int i=0;i<N;i++)
        scanf("%s", newp[i]);
    if (deg_90(oldp))
        printf("%d\n",1);
    else if (deg_180(oldp))
        printf("%d\n",2);
    else if (deg_270(oldp))
        printf("%d\n",3);
    else if (reflect(oldp))
        printf("%d\n",4);
    else if (combine(oldp))
        printf("%d\n",5);
    else if (no_change(oldp))
        printf("%d\n",6);
    else printf("%d\n",7);
}

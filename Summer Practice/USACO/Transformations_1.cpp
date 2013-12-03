/*
ID: malataw1
PROG: transform
LANG: C++
*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

typedef vector<string> grid;

int N;
grid g, tg;

grid rot90(grid vs){
    grid ng(N,"");
    for (int i=N-1;i>=0;i--)
        for (int j=0;j<N;j++){
            ng[j]+=vs[i][j];
        }
    return ng;
}

grid ref(grid vs){
    grid ng(N,"");
    for (int i=N-1;i>=0;i--)
        for (int j=0;j<N;j++){
            ng[j]+=vs[j][i];
        }
    return ng;
}

int eq(grid vs){
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (vs[i][j]!=tg[i][j])
                return 0;
    return 1;
}

int check(){
    grid ng = rot90(g);
    if (eq(ng))
        return 1;
    ng = rot90(ng);
    if (eq(ng))
        return 2;
    ng = rot90(ng);
    if (eq(ng))
        return 3;
    ng = ref(g);
    if (eq(ng))
        return 4;
    ng = rot90(ng);
    if (eq(ng))
        return 5;
    ng = rot90(ng);
    if (eq(ng))
        return 5;
    ng = rot90(ng);
    if (eq(ng))
        return 5;
    if (eq(g))
        return 6;
    return 7;
}

int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>N;
    string s;
    for (int i=0;i<N;i++){
        cin>>s;
        g.push_back(s);
    }
    for (int i=0;i<N;i++){
        cin>>s;
        tg.push_back(s);
    }
    printf("%d\n", check());
}

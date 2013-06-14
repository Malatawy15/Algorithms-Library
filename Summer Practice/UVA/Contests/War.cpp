#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int pset[10010];
set<int> enemies[10010];

int find_set(int p){
    return pset[p]==p?p:find_set(pset[p]);
}

int union_set(int p, int q){
    int p1 = find_set(p), p2 = find_set(q);
    if (enemies[p1].size()<enemies[p2].size()){

    }
}

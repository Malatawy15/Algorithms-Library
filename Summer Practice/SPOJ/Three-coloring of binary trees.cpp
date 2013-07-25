#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

int dpMax [10010][2];
int dpMin [10010][2];
int N;
string inp;
int children[10010][2];

void calculate(int n, int isGreen){
    if (n==N)
        return;
    if (dpMax[n][isGreen]!=-1)
        return;
    if (isGreen){
        if (inp[n]=='0'){
            dpMax[n][isGreen] = 1;
            dpMin[n][isGreen] = 1;
        }
        else if (inp[n]=='1'){
            calculate(children[n][0],!isGreen);
            dpMax[n][isGreen] = 1+dpMax[children[n][0]][!isGreen];
            dpMin[n][isGreen] = 1+dpMin[children[n][0]][!isGreen];
        }
        else{
            calculate(children[n][0],!isGreen);
            calculate(children[n][1],!isGreen);
            dpMax[n][isGreen] = 1+dpMax[children[n][0]][!isGreen]+dpMax[children[n][1]][!isGreen];
            dpMin[n][isGreen] = 1+dpMin[children[n][0]][!isGreen]+dpMin[children[n][1]][!isGreen];
        }
    }
    else{
        if (inp[n]=='0'){
            dpMax[n][isGreen] = 0;
            dpMin[n][isGreen] = 0;
        }
        else if (inp[n]=='1'){
            calculate(children[n][0],!isGreen);
            calculate(children[n][0],isGreen);
            dpMax[n][isGreen] = max(dpMax[children[n][0]][isGreen], dpMax[children[n][0]][!isGreen]);
            dpMin[n][isGreen] = min(dpMin[children[n][0]][isGreen], dpMin[children[n][0]][!isGreen]);
        }
        else{
            calculate(children[n][0],!isGreen);
            calculate(children[n][0],isGreen);
            calculate(children[n][1],!isGreen);
            calculate(children[n][1],isGreen);
            dpMax[n][isGreen] = max(dpMax[children[n][0]][isGreen]+dpMax[children[n][1]][!isGreen], dpMax[children[n][0]][!isGreen]+dpMax[children[n][1]][isGreen]);
            dpMin[n][isGreen] = min(dpMin[children[n][0]][isGreen]+dpMin[children[n][1]][!isGreen], dpMin[children[n][0]][!isGreen]+dpMin[children[n][1]][isGreen]);
        }
    }
}
int node;
void form_tree(){
    if (node==N)
        return;
    int c_node = node;
    node++;
    if (inp[c_node]=='1'){
        children[c_node][0] = node;
        form_tree();
    }
    else if (inp[c_node]=='2'){
        children[c_node][0] = node;
        form_tree();
        children[c_node][1] = node;
        form_tree();
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>inp;
        N = inp.size();
        memset(dpMax, -1, sizeof dpMax);
        node = 0;
        form_tree();
        calculate(0,0);
        calculate(0,1);
        printf("%d %d\n", max(dpMax[0][0],dpMax[0][1]), min(dpMin[0][0], dpMin[0][1]));
    }
}

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int ele [20];

void seq (){
    int n = N, st = 1, tp = 0;
    vector<int> vec;
    vector<int> vec1;
    if(n%2){
        tp = 1;
        n--;
    }
    for (int i=0;i<n;i+=2){
        vec.push_back(ele[i]|ele[i+1]);
    }
    if (tp)
        vec.push_back(ele[N-1]);
    while(true){
        n = st?vec.size():vec1.size();
        if (n==1)
            break;
        tp = 0;
        if(n%2){
            tp = 1;
            n--;
        }
        for (int i=0;i<n;i+=2){
            if (st){
                vec1.push_back(vec[i]^vec[i+1]);
            }
            else {
                vec.push_back(vec1[i]|vec1[i+1]);
            }
        }
        if (tp)
            if (st)
                vec1.push_back(vec[n]);
            else vec.push_back(vec1[n]);
        st = st?0:1;
    }
    printf("%d\n", st?vec[0]:vec1[0]);
}

int main(){
    int x,y;
    scanf("%d %d", &x, &M);
    N = 1;
    for (int i=0;i<x;i++)
        N<<=1;
}

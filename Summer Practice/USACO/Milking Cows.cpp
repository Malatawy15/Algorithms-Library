/*
ID: malataw1
PROG: milk2
LANG: C++
*/

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Pair pair<int, int>

int main(){
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int N,s,e;
    scanf("%d", &N);
    vector<Pair> pts;
    while(N--){
        scanf("%d %d", &s, &e);
        pts.push_back(Pair(s,0));
        pts.push_back(Pair(e,1));
    }
    sort (pts.begin(), pts.end());
    int maxOn=-1, maxOff=-1, cows = -1, st=0;
    for (int i=0;i<pts.size();i++){
        if (cows==0){
            if (pts[i].first-st>maxOff)
                maxOff = pts[i].first-st;
            st = pts[i].first;
            cows++;
        }
        else{
            if (!pts[i].second)
                if (cows==-1){
                    cows=1;
                    st = pts[i].first;
                }else cows++;
            else if(cows==1){
                if (pts[i].first-st>maxOn)
                    maxOn = pts[i].first-st;
                    st = pts[i].first;
                    cows--;
            }
            else {
                cows--;
            }
        }
    }
    printf("%d %d\n", maxOn, maxOff==-1?0:maxOff);
}

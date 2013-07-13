#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
#define Wine pair<int, int>
#define id first
#define cost second

int main(){
    int N,x;
    scanf("%d",&N);
    while(N){
        vector<Wine> pos;
        vector<Wine> neg;
        for (int i=0;i<N;i++){
            scanf("%d",&x);
            if (x>0)
                pos.push_back(Wine(i,x));
            else neg.push_back(Wine(i,x));
        }
        long long sum = 0LL;
        int ind = 0;
        for (int i=0;i<pos.size();i++){
            while(pos[i].cost){
                if (-1*neg[ind].cost>=pos[i].cost){
                    sum+=(abs(neg[ind].id-pos[i].id)*pos[i].cost);
                    neg[ind].cost+=pos[i].cost;
                    pos[i].cost = 0;
                }
                else{
                    sum+=(abs(neg[ind].id-pos[i].id)*neg[ind].cost*-1);
                    pos[i].cost+=neg[ind].cost;
                    neg[ind].cost = 0;
                    ind++;
                }
            }
        }
        printf("%lld\n",sum);
        scanf("%d",&N);
    }
}

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, cn;
        scanf("%d", &cn);
        vector<int> v;
        for (int i=0;i<10;i++){
            scanf("%d", &a);
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        printf("%d %d\n", cn, v[7]);
    }
}

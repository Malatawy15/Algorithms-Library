#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int elements [32];
vector<int> vec;

int main(){
    int t, cn = 1, tmp;
    scanf("%d", &t);
    while(t--){
        vec.clear();
        scanf("%d", &N);
        for (int i=1;i<=N;i++)
            scanf("%d", &elements[i]);
        while(N>=1){
            int max = -1, maxi;
            for (int i=1;i<=N;i++){
                if (abs(elements[i])>max){
                    max = abs(elements[i]);
                    maxi = i;
                }
            }
            if (maxi==N&&elements[N]>0){
                N--;
                continue;
            }
            if (maxi!=1)
            for (int i=1;i<=(maxi>>1)+maxi%2;i++){
                tmp = elements[i];
                elements[i] = -1*elements[maxi-i+1];
                elements[maxi-i+1] = -1*tmp;
            }
            if (maxi!=1)
            vec.push_back(maxi);
            if (elements[1]>0){
                vec.push_back(1);
                elements[1]*=-1;
            }
            vec.push_back(N);
            maxi = N;
            for (int i=1;i<=(maxi>>1)+maxi%2;i++){
                tmp = elements[i];
                elements[i] = -1*elements[maxi-i+1];
                elements[maxi-i+1] = -1*tmp;
            }
            N--;
        }
        if (vec.size()==0){
            printf("%d %d\n",cn++,0);
            continue;
        }
        printf("%d %d",cn++,vec.size());
        for (int i=0;i<vec.size();i++)
            printf(" %d", vec[i]);
        printf("\n");
    }
}

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int N;
vector<int> vec;
int vis [100001];


int binarySearch(int s){
    int low = 0, high = N-1, mid;
    for (int i=0;i<20;i++){
        if (low>high)
            return -1;
        if (low==high){
            if (!vis[low]&&vec[low]>vec[s]&&vec[low]%vec[s]==0)
                return low;
            else return -1;
        }
        mid = (low+high)>>1;
        if (!vis[mid]&&vec[mid]>vec[s]&&vec[mid]%vec[s]==0)
            high = mid;
        else low = mid;
    }
    return -1;
}


int clusterize(){
    int cnt = 0,n1,n2;
    for (int i=0;i<N;i++){
        if (vis[i]==0){
            n1 = binarySearch(i);
            if (n1==-1)
                return 0;
            n2 = binarySearch(n1);
            if (n2==-1)
                return 0;
            cnt++;
            vis[i] = cnt;
            vis[n1] = cnt;
            vis[n2] = cnt;
        }
    }
    return 1;
}

int main(){
    scanf("%d", &N);
    int x, c = 0;
    for (int i=0;i<N;i++){
        scanf("%d", &x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    memset(vis,0,sizeof vis);
    if (clusterize()){
        for (int i=0;i<N;i++)

    }
    else prinf("-1\n");
}


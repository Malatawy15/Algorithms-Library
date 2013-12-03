#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int N, flag;
vector<int> v1;
vector<int> v2;
int sor[1001][1001];
int arr[1001][1001];

int check_ring(int ind){
    v1.clear();
    v2.clear();
    int st = -1, tbf = sor[ind][ind];
    for (int i=ind;i<N-ind;i++){
        v1.push_back(sor[ind][i]);
        v2.push_back(arr[ind][i]);
        if (tbf==arr[ind][i])
            st = v2.size()-1;
    }
    for (int i=ind+1;i<N-ind;i++){
        v1.push_back(sor[i][N-ind-1]);
        v2.push_back(arr[i][N-ind-1]);
        if (tbf==arr[i][N-ind-1])
            st = v2.size()-1;
    }
    for (int i=N-ind-2;i>=ind;i--){
        v1.push_back(sor[N-ind-1][i]);
        v2.push_back(arr[N-ind-1][i]);
        if (tbf==arr[N-ind-1][i])
            st = v2.size()-1;
    }
    for (int i=N-ind-2;i>ind;i--){
        v1.push_back(sor[i][ind]);
        v2.push_back(arr[i][ind]);
        if (tbf==arr[i][ind])
            st = v2.size()-1;
    }
    /*
    printf("%d: ",ind);
    for (int i=0;i<v1.size();i++)
        printf("%d ",v1[i]);
    printf("\n%d: ",ind);
    for (int i=0;i<v2.size();i++)
        printf("%d ",v2[i]);
    printf("\n");
    */
    if (st==-1)
        return 0;
    for (int i=1;i<v1.size();i++){
        if (v1[i]!=v2[(st+i)%v2.size()])
            return 0;
    }
    return 1;
}

int check(){
    if (N%2==1){
        if (sor[N>>1][N>>1]!=arr[N>>1][N>>1])
            return 0;
    }
    for (int i=0;i<N>>1;i++)
        if (!check_ring(i))
            return 0;
    return 1;
}

int main(){
    int cn = 1;
    scanf("%d", &N);
    while(N){
        v1.clear();
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++){
                scanf("%d",&arr[i][j]);
                v1.push_back(arr[i][j]);
            }
        sort(v1.begin(), v1.end());
        int ind = 0;
        flag = 1;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++){
                if (v1[ind]!=ind+1){
                    flag = 0;
                    break;
                }
                sor[i][j] = v1[ind++];
            }

        if (flag&&check()){
            printf("%d. YES\n",cn++);
        }
        else {
            printf("%d. NO\n",cn++);
        }
        scanf("%d", &N);
    }
}

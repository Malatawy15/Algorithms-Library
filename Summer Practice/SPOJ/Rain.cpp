#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N, M;
long long S[1500010];
long long T[1500010];
int A[1500010];

void calc(){
    for (int i=1;i<=N;i++){
        S[i] = (78901 + 31*S[i-1]) % 699037;
        T[i] = (23456 + 64*T[i-1]) % 2097151;
        A[i] = (S[i] % 100 + 1) * (T[i] % 100 + 1);
        //printf("%d ", A[i]);
    }
}

int main(){
    int t, si, maxi = 0, csf, f;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &S[0], &T[0], &N, &M);
        calc();
        csf = si = 0;
        maxi = N;
        for (int i=1;i<=N;i++){
            f = 0;
            csf+=A[i];
            while(csf>M){
                si++;
                csf-=A[si];
                f = 1;
            }
            if (f)
                maxi = min(maxi, i-si);
        }
        printf("%d\n", maxi);
    }
}

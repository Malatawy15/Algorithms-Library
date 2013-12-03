/*
ID: malataw1
PROG: crypt1
LANG: C++
*/

#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N;
vector<int> nums;
int exists [10];

int check(int num){
    while(num>0){
        if (!exists[num%10]) return 0;
        num/=10;
    }
    return 1;
}

int count(int a, int b){
    int sum = 0;
    if (a/100==0){
        for (int i=0;i<N;i++) sum+=count(a*10+nums[i],b);
    }
    else if (b/10==0){
        for (int i=0;i<N;i++) sum+=count(a,b*10+nums[i]);
    }
    else {
        if ((a*b)/10000>0) return 0;
        int b1 = b%10, b2 = b/10;
        int ab1=a*b1, ab2=a*b2;
        if ((ab1)/1000>0) return 0;
        if ((ab2)/1000>0) return 0;
        if (!check(ab1)) return 0;
        if (!check(ab2)) return 0;
        if (!check(ab1+ab2*10)) return 0;
        return 1;
    }
    return sum;
}

int main(){
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    scanf("%d", &N);
    int a;
    for (int i=0;i<N;i++){
        scanf("%d", &a);
        exists[a] = 1;
        nums.push_back(a);
    }
    printf("%d\n",count(0,0));
}

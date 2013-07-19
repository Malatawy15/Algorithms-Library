#include<stdio.h>
#include<map>

using namespace std;

map<int, long long> dp;
map<int, long long>::iterator it;

int pows10[10];

long long calc(int a, int b){
    int aa [10];
    int bb [10];
    for (int i=0;i<10;i++){
        aa[i] = 0;
        bb[i] = 0;
    }
    int ind = 0;
    while(a!=0){
        aa[ind++] = a%10;
        a/=10;
    }
    ind = 0;
    while(b!=0){
        bb[ind++] = b%10;
        b/=10;
    }
    //for (int i=0;i<10;i++){
      //  printf("%d %d\n",aa[i],bb[i]);
    //}
    int flag = 0;
    long long sum = 0LL;
    for (int i=aa[9];i<=9;i++)
        for (int j=flag==1?0:aa[8];j<=9;j++)
            for (int k=flag==1?0:aa[7];k<=9;k++)
                for (int l=flag==1?0:aa[6];l<=9;l++)
                    for (int m=flag==1?0:aa[5];m<=9;m++)
                        for (int n=flag==1?0:aa[4];n<=9;n++)
                            for (int o=flag==1?0:aa[3];o<=9;o++)
                                for (int p=flag==1?0:aa[2];p<=9;p++)
                                    for (int q=flag==1?0:aa[1];q<=9;q++)
                                        for (int r=flag==1?0:aa[0];r<=9;r++){
                                            //printf("%d%d%d%d%d%d%d%d%d%d\n",i,j,k,l,m,n,o,p,q,r);
                                            //printf("%d%d%d%d%d%d%d%d%d%d\n",i==bb[9],j==bb[8],k==bb[7],l==bb[6],m==bb[5],n==bb[4],o==bb[3],p==bb[2],q==bb[1],r==bb[0]);
                                            sum+=(i+j+k+l+m+n+o+p+q+r);
                                            if (!flag)
                                                flag = 1;
                                            if (i==bb[9]&&j==bb[8]&&k==bb[7]&&l==bb[6]&&m==bb[5]&&n==bb[4]&&o==bb[3]&&p==bb[2]&&q==bb[1]&&r==bb[0])
                                                return sum;
                                        }
}


long long memoize(int N){
    int n = N;
    if (n==0)
        return 0;
    if (n<10)
        return (n*(n+1))>>1;
    it = dp.find(N);
    if (it!=dp.end())
        return it->second;
    int arr [10];
    for (int i=0;i<10;i++)
        arr[i] = 0;
    int ind = 0;
    while(n!=0){
        arr[ind++] = n%10;
        n/=10;
    }
    ind--;
    long long sum = 0LL;
    n = pows10[ind]*arr[ind];
    sum+=memoize(N-n);
    sum+=(arr[ind]*(N-n));
    sum+=arr[ind];
    for (int i=0;i<ind;i++){
        long long calc = 0LL;
        calc+=45;
        calc*=arr[ind];
        calc*=pows10[ind-i-1];
        calc*=pows10[i];
        sum+=calc;
    }
    sum+=(((arr[ind]*(arr[ind]-1))>>1)*pows10[ind]);
    dp.insert(make_pair(N,sum));
    return sum;
}

int main(){
    pows10[0] = 1;
    for (int i=1;i<10;i++)
        pows10[i] = pows10[i-1]*10;
    int a, b,x;
    scanf("%d %d",&a,&b);
    while(!(a==-1&&b==-1)){
        x = a;
        long long sum = 0LL;
        while(x!=0){
            sum+= x%10;
            x/=10;
        }
        //printf("%lld\n",calc(a,b));
        printf("%lld\n",sum+memoize(b)-memoize(a));
        scanf("%d %d",&a,&b);
    }
}


#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int isPrime[10010];
int powers[10010];
vector<int> primes;

void sieve(){
    memset(isPrime, 0, sizeof isPrime);
    isPrime[0] = isPrime[1] = 1;
    for (int i=2;i<10010;i++){
        if (isPrime[i])
            continue;
        primes.push_back(i);
        for (int j = i*i;j<10010;j+=i)
            isPrime[j] = 1;
    }
}

void factorize(int n){
    for (int i=0;i<primes.size()&&n>1;i++){
        if (n%primes[i]==0)
        while(n>1&&n%primes[i]==0){
            powers[primes[i]]++;
            n/=primes[i];
        }
    }
}

int main(){
    memset(powers,0,sizeof powers);
    sieve();
    int N, f = 1;
    scanf("%d", &N);
    for (int i=2;i<=N;i++)
        factorize(i);
    for (int i=0;i<primes.size();i++)
    if (powers[primes[i]]){
        if (f)
            f = 0;
        else printf(" * ");
        printf("%d^%d", primes[i], powers[primes[i]]);
    }
}

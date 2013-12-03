#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

vector<ll> sumSqrs;
vector<ll>::iterator it;

void initSumSqrs(){
    ll i=2;
    sumSqrs.push_back(1);
    while(sumSqrs.back()<1000000000000000000ll){
        sumSqrs.push_back(sumSqrs.back()+i*i);
        i++;
    }
}

ll sumOdds[2000000];

void initSumOdds(){
    ll i=1;
    sumOdds[0]=1LL;
    for(int j=1; j<2000000; j++){
        sumOdds[j]=sumOdds[j-1]+2*j+1;
        //if (j<10)
        //printf("%d %lld\n",j,sumOdds[j]);
    }
}

int main(){
    //freopen("army.in", "r", stdin);
    int i,j,k, t;
    ll n, row, midsum, len, x, rest, kase=1;

    initSumSqrs();
    initSumOdds();

    //scanf("%d", &t);
    cin>>t;
    while(t--){
    //    scanf("%lld", &n);
        cin>>n;
        it = lower_bound(sumSqrs.begin(), sumSqrs.end(), n);
        row = it-sumSqrs.begin();
        //printf("ROW: %d %d\n", sumOdds[row],sumOdds[row]);
        if(binary_search(sumSqrs.begin(), sumSqrs.end(), n)){
            cout<<"Case "<<kase++<<": "<<ll(sumOdds[row])<<endl;
            //printf("Case %d: %lld\n", kase++, sumOdds[row]);
            continue;
        }

        len = 2*row+1;
        midsum = (len/2+1)*(len/2+2)/2;

        if(row>0) n-=sumSqrs[row-1];

        if(n<=midsum){
            x = ceil((ll)(sqrt(2*n+0.25)-0.5));
            cout<<"Case "<<kase++<<": "<<ll(sumOdds[row-1]+x)<<endl;
            //printf("Case %d: %lld\n", kase++, );
        }else{
            n-=midsum;
            midsum = (len/2)*(len/2+1)/2;
            rest = midsum-n;
            x = ceil((ll)(sqrt(2*rest+0.25)-0.5));
            cout<<"Case "<<kase++<<": "<<ll(sumOdds[row-1]+len/2+1+len/2-x)<<endl;
            //printf("Case %d: %lld\n", kase++, );
        }
    }
    return 0;
}

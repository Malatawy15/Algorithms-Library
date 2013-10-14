#include<iostream>
 using namespace std;

 int main(){
     int N, M, nt;
     cin>>N>>M;
     long long sum = 0LL;
     int in = 0;
     for (int i=0;i<M;i++){
        cin>>nt;
        nt--;
        if (in<=nt)
            sum+=(nt-in);
        else{
            sum+=(N-in+nt);
        }
        in = nt;
     }
     cout<<sum<<endl;
 }

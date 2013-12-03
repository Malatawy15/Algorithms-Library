#include<string>
#include<iostream>


using namespace std;

int main(){
    int t, x,y;
    cin>>t;
    string s;
    while(t--){
        cin>>x>>y>>s;
        string res = "";
        for (int i=0;i<s.size();i++){
            for (int j=0;j<y;j++){
                res+=s[i];
            }
        }
        cout<<x<<" "<<res<<endl;
    }
}

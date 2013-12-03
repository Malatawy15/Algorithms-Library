#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<string>bef;
        vector<string>aft;
        string eng, w;
        int f = 0;
        for (int i=0;i<n;i++){
            cin>>w;
            if (w[0]=='#'){
                if (f){
                    aft.push_back(w);
                }
                else {
                    bef.push_back(w);
                }
            }
            else{
                eng = w;
                f = 1;
            }
        }
        if (f){
            if (aft.size()>0){
                cout<<aft[0];
                for (int i=1;i<aft.size();i++)
                    cout<<" "<<aft[i];
                cout<<" "<<eng;
            }
            else cout<<eng;
            for (int i=0;i<bef.size();i++)
                cout<<" "<<bef[i];
        }
        else {
                cout<<bef[0];
            for (int i=1;i<bef.size();i++)
                cout<<" "<<bef[i];
        }
        cout<<endl;
    }
}

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    while(scanf("%d", &N)>0){
        int a;
        vector<pair<int,int> > v;
        for (int i=0;i<N;i++){
            scanf("%d", &a);
            v.push_back(make_pair(a,i));
        }
        //sort(v.begin(),v.end());
        vector<int> vv;
        for (int i=1;i<N;i++){
            if (v[i].first>v[i-1].first&&v[i].first>v[i+1].first&&v[i].first>=150000)
                vv.push_back(v[i].second);
        }
        //sort(vv.begin(),vv.end());
        printf("%d",vv[0]+1);
        for (int i=1;i<vv.size();i++){
            printf(" %d",vv[i]+1);
        }
        printf("\n");
    }
}

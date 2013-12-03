#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int s1,s2,s3,s4,s5,s6;
    scanf("%d %d %d %d %d %d",&s1,&s2,&s3,&s4,&s5,&s6);
    while(!(!s1&&!s2&&!s3&&!s4&&!s5&&!s6)){
        vector<int> v;
        v.push_back(s1);
        v.push_back(s2);
        v.push_back(s3);
        v.push_back(s4);
        v.push_back(s5);
        v.push_back(s6);
        sort(v.begin(), v.end());
        int sum = 0;
        for (int i=1;i<5;i++){
            sum+=v[i];
        }
        int ss = sum%4;
        switch(ss){
            case 0: printf("%d\n",sum/4);break;
            case 1: printf("%d.25\n",sum/4);break;
            case 2: printf("%d.5\n",sum/4);break;
            case 3: printf("%d.75\n",sum/4);break;
        }
        scanf("%d %d %d %d %d %d",&s1,&s2,&s3,&s4,&s5,&s6);
    }
}

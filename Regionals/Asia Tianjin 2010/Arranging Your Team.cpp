#include<iostream>
#include<map>
#include<string>

using namespace std;

int M;
int details [23][2];
int power [1000000][3];

int maximize(){
    int gg,dd,mm,aa, maxi = -1000000000, cur;
    for (int a = 0;a<23;a++)
    for (int b = a+1;b<23;b++)
    for (int c = b+1;c<23;c++)
    for (int d = c+1;d<23;d++)
    for (int e = d+1;e<23;e++)
    for (int f = e+1;f<23;f++)
    for (int g = f+1;g<23;g++)
    for (int h = g+1;h<23;h++)
    for (int i = h+1;i<23;i++)
    for (int j = i+1;j<23;j++)
    for (int k = j+1;k<23;k++){
        gg = 0,dd = 0,mm = 0,aa = 0;
        if (details[a][1]==0)gg++;else if (details[a][1]==1)dd++;else if(details[a][1]==2)mm++;else aa++;
        if (details[b][1]==0)gg++;else if (details[b][1]==1)dd++;else if(details[b][1]==2)mm++;else aa++;
        if (details[c][1]==0)gg++;else if (details[c][1]==1)dd++;else if(details[c][1]==2)mm++;else aa++;
        if (details[d][1]==0)gg++;else if (details[d][1]==1)dd++;else if(details[d][1]==2)mm++;else aa++;
        if (details[e][1]==0)gg++;else if (details[e][1]==1)dd++;else if(details[e][1]==2)mm++;else aa++;
        if (details[f][1]==0)gg++;else if (details[f][1]==1)dd++;else if(details[f][1]==2)mm++;else aa++;
        if (details[g][1]==0)gg++;else if (details[g][1]==1)dd++;else if(details[g][1]==2)mm++;else aa++;
        if (details[h][1]==0)gg++;else if (details[h][1]==1)dd++;else if(details[h][1]==2)mm++;else aa++;
        if (details[i][1]==0)gg++;else if (details[i][1]==1)dd++;else if(details[i][1]==2)mm++;else aa++;
        if (details[j][1]==0)gg++;else if (details[j][1]==1)dd++;else if(details[j][1]==2)mm++;else aa++;
        if (details[k][1]==0)gg++;else if (details[k][1]==1)dd++;else if(details[k][1]==2)mm++;else aa++;
        if (gg!=1||dd!=4||mm!=4||aa!=2)
            continue;
        cur = details[a][0]+details[b][0]+details[c][0]+details[d][0]+details[e][0]+details[f][0]+details[g][0]+details[h][0]+details[i][0]+details[j][0]+details[k][0];
        for (int ind = 0;ind<M;ind++){
            if ((power[ind][0]==a||power[ind][0]==b||power[ind][0]==c||power[ind][0]==d||power[ind][0]==e||power[ind][0]==f||power[ind][0]==g||power[ind][0]==h||power[ind][0]==i||power[ind][0]==j||power[ind][0]==k)
                &&(power[ind][1]==a||power[ind][1]==b||power[ind][1]==c||power[ind][1]==d||power[ind][1]==e||power[ind][1]==f||power[ind][1]==g||power[ind][1]==h||power[ind][1]==i||power[ind][1]==j||power[ind][1]==k))
                    cur+=power[ind][2];
        }
        if (cur>maxi)
            maxi = cur;
    }
    return maxi;
}

int main(){
    string s;
    map<string, int> mp;
    while(cin>>s){
        int g =0,d=0,m=0,a=0;
        mp.clear();
        mp.insert(make_pair(s, 0));
            cin>>details[0][0];
            cin>>s;
            if (s[0]=='g'){
                details[0][1] = 0;
                g++;
            }
            else if (s[0]=='d'){
                details[0][1] = 1;
                d++;
            }
            else if (s[0]=='m'){
                details[0][1] = 2;
                m++;
            }
            else{
                details[0][1] = 3;
                a++;
            }
        for (int i=1;i<23;i++){
            cin>>s;
            mp.insert(make_pair(s, i));
            cin>>details[i][0];
            cin>>s;
            if (s[0]=='g'){
                details[i][1] = 0;
                g++;
            }
            else if (s[0]=='d'){
                details[i][1] = 1;
                d++;
            }
            else if (s[0]=='m'){
                details[i][1] = 2;
                m++;
            }
            else{
                details[i][1] = 3;
                a++;
            }
        }
        cin>>M;
        for (int i=0;i<M;i++){
            cin>>s;
            power[i][0] = mp.find(s)->second;
            cin>>s;
            power[i][1] = mp.find(s)->second;
            cin>>power[i][2];
        }
        if (g<1||d<4||m<4||a<2)
            cout<<"impossible\n";
        else{
        	int ret = maximize();
        	if (ret!=-1000000000)
        		cout<<ret<<"\n";
        	else cout<<"impossible\n";
        }
    }
}

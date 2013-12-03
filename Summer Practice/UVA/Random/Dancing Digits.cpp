#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

int cn, zs;
int isPrime[20];
int vis[8][8][8][8][8][8][8][8];

struct state{
    int cs;
    vi v;
};

int bfs(vi init){
    queue<state> q;
    state s;
    s.v = vi(init);
    s.cs = 0;
    q.push(s);
    vis[abs(s.v[0])-1][abs(s.v[1])-1][abs(s.v[2])-1][abs(s.v[3])-1][abs(s.v[4])-1][abs(s.v[5])-1][abs(s.v[6])-1][abs(s.v[7])-1] = cn;
    while(!q.empty()){
        s = q.front();
        q.pop();
        if (abs(s.v[0])==1&&abs(s.v[1])==2&&abs(s.v[2])==3&&abs(s.v[3])==4&&abs(s.v[4])==5&&abs(s.v[5])==6&&abs(s.v[6])==7&&abs(s.v[7])==8)
            return s.cs;
        for (int i=0;i<8;i++){
            for (int j=i+1;j<8;j++){
                if (((s.v[i]>0&&s.v[j]<0)||(s.v[j]>0&&s.v[i]<0))&&isPrime[abs(s.v[i])+abs(s.v[j])]){
                    state s1,s2,s3,s4;
                    for (int k=0;k<i;k++)
                        s1.v.push_back(s.v[k]);
                    for (int k=0;k<=i;k++)
                        s2.v.push_back(s.v[k]);
                    s1.v.push_back(s.v[j]);
                    s1.v.push_back(s.v[i]);
                    s2.v.push_back(s.v[j]);
                    for (int k=i+1;k<8;k++){
                        if (k!=j){
                            s1.v.push_back(s.v[k]);
                            s2.v.push_back(s.v[k]);
                        }
                    }
                    for (int k=0;k<j;k++){
                        if (k!=i){
                            s3.v.push_back(s.v[k]);
                            s4.v.push_back(s.v[k]);
                        }
                    }
                    s3.v.push_back(s.v[j]);
                    s3.v.push_back(s.v[i]);
                    s4.v.push_back(s.v[i]);
                    s4.v.push_back(s.v[j]);
                    for (int k=j+1;k<8;k++){
                        s3.v.push_back(s.v[k]);
                        s4.v.push_back(s.v[k]);
                    }
                    s1.cs = s.cs+1;
                    s2.cs = s.cs+1;
                    s3.cs = s.cs+1;
                    s4.cs = s.cs+1;
                    if (vis[abs(s1.v[0])-1][abs(s1.v[1])-1][abs(s1.v[2])-1][abs(s1.v[3])-1][abs(s1.v[4])-1][abs(s1.v[5])-1][abs(s1.v[6])-1][abs(s1.v[7])-1] != cn){
                        vis[abs(s1.v[0])-1][abs(s1.v[1])-1][abs(s1.v[2])-1][abs(s1.v[3])-1][abs(s1.v[4])-1][abs(s1.v[5])-1][abs(s1.v[6])-1][abs(s1.v[7])-1] = cn;
                        q.push(s1);
                    }
                    if (vis[abs(s2.v[0])-1][abs(s2.v[1])-1][abs(s2.v[2])-1][abs(s2.v[3])-1][abs(s2.v[4])-1][abs(s2.v[5])-1][abs(s2.v[6])-1][abs(s2.v[7])-1] != cn){
                        vis[abs(s2.v[0])-1][abs(s2.v[1])-1][abs(s2.v[2])-1][abs(s2.v[3])-1][abs(s2.v[4])-1][abs(s2.v[5])-1][abs(s2.v[6])-1][abs(s2.v[7])-1] = cn;
                        q.push(s2);
                    }
                    if (vis[abs(s3.v[0])-1][abs(s3.v[1])-1][abs(s3.v[2])-1][abs(s3.v[3])-1][abs(s3.v[4])-1][abs(s3.v[5])-1][abs(s3.v[6])-1][abs(s3.v[7])-1] != cn){
                        vis[abs(s3.v[0])-1][abs(s3.v[1])-1][abs(s3.v[2])-1][abs(s3.v[3])-1][abs(s3.v[4])-1][abs(s3.v[5])-1][abs(s3.v[6])-1][abs(s3.v[7])-1] = cn;
                        q.push(s3);
                    }
                    if (vis[abs(s4.v[0])-1][abs(s4.v[1])-1][abs(s4.v[2])-1][abs(s4.v[3])-1][abs(s4.v[4])-1][abs(s4.v[5])-1][abs(s4.v[6])-1][abs(s4.v[7])-1] != cn){
                        vis[abs(s4.v[0])-1][abs(s4.v[1])-1][abs(s4.v[2])-1][abs(s4.v[3])-1][abs(s4.v[4])-1][abs(s4.v[5])-1][abs(s4.v[6])-1][abs(s4.v[7])-1] = cn;
                        q.push(s4);
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    isPrime[1] = 0;isPrime[4] = 0;isPrime[7] = 1;isPrime[10] = 0;isPrime[13] = 1;
    isPrime[2] = 1;isPrime[5] = 1;isPrime[8] = 0;isPrime[11] = 1;isPrime[14] = 0;
    isPrime[3] = 1;isPrime[6] = 0;isPrime[9] = 0;isPrime[12] = 0;isPrime[15] = 0;
    cn = 0;
    vi init;
    int in;
    scanf("%d", &in);
    while(in!=0){
        cn++;
        init.clear();
        init.push_back(in);
        for (int i=0;i<7;i++){
            scanf("%d", &in);
            init.push_back(in);
        }
        printf("Case %d: %d\n",cn, bfs(init));
        scanf("%d", &in);
    }
}

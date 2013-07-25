#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define Doll pair<int, int>

vector<Doll> widths;
vector<Doll> heights;
vector<Doll>::iterator it;

int vis[20010];
int dolls[20010][2];
int N, sum;

void enclose(int n){
    int w = widths[n].first;
    int h = dolls[widths[n].second][1];
    it = lower_bound(heights.begin(), heights.end(), Doll(h,n));
    vis[n] = 1;
    for (;it!=heights.end();++it)
        if (h<(*it).first&&!vis[(*it).second]&&widths[(*it).second].first>w){
            enclose((*it).second);
            sum--;
            break;
        }
}

int main(){
    int t,x,y;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%d %d", &x, &y);
            dolls[i][0] = x;
            dolls[i][1] = y;
            widths.push_back(Doll(x,i));
        }
        sort(widths.begin(), widths.end());
        for (int i=0;i<N;i++)
            heights.push_back(Doll(dolls[widths[i].second][1],i));
        sort(heights.begin(), heights.end());
        sum = N;
        memset(vis,0,sizeof vis);
        for (int i=0;i<N;i++)
            if (!vis[i])
                enclose(i);
        printf("%d\n",sum);
        widths.clear();
        heights.clear();
    }
}

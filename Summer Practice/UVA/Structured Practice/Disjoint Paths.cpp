#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int N, K;

typedef pair<int, int> ii;

vector<ii> graph[61];
vector<ii> graphD[61];

int dp [61][2][61];

int recur(int n, int root, int k){

}

int main(){
    int t,a,b,c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &K);
        for (int i=0;i<N;i++)
            graph[i].clear();
        for (int i=0;i<N-1;i++){
            scanf("%d %d %d", &a, &b, &c);
            a--;b--;
            graph[a].push_back(ii(b,c));
            graph[b].push_back(ii(a,c));
        }
    }
}

#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int vis [27];
int count [27];
int current;
char inp [1000000];


void construct_path(){
    stack<int> st;
    int n;
    int size = strlen(inp);
    n = inp[0]-'A';
    vis[n] = 1;
    count[n]--;
    st.push(n);
    for (int i =1;i<size;i++){
        n = inp[i]-'A';
        if (vis[n]){
            st.pop();
        }
        else{
            vis[n] = 1;
            count[st.top()]++;
            st.push(n);
        }
    }
}


int main(){
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        memset(vis, 0, sizeof vis);
        memset(count, 0, sizeof count);
        scanf("%s", inp);
        construct_path();
        printf("Case %d\n",i+1);
        for (int j = 0;j<26;j++){
            if (vis[j]){
                printf("%c = %d\n",'A'+j, count[j]+1);
            }
        }
    }
}

#include<stdio.h>

using namespace std;

struct node{
    int left, right;
    node(){
        left = -1, right = -1;
    }
    node(int l, int r){
        left = l;
        right = r;
    }
};

int main(){
    int N, Q, L, R, nl, nr;
    scanf("%d %d", &N, &Q);
    while(!(!N&&!Q)){
        node arr [N+1];
        for (int i=2;i<N;i++){
            arr[i] = node(i-1,i+1);
        }
        if (N!=1){
            arr[1] = node(-1,2);
            arr[N] = node(N-1,-1);
        }
        while(Q--){
            scanf("%d %d", &L, &R);
            nl = arr[L].left;
            nr = arr[R].right;
            if (nl!=-1)
                arr[nl].right = nr;
            if (nr!=-1)
                arr[nr].left = nl;
            if (nl==-1)
                printf("* ");
            else printf("%d ", nl);
            if (nr==-1)
                printf("*\n");
            else printf("%d\n",nr);
        }
        printf("-\n");
        scanf("%d %d", &N, &Q);
    }
}

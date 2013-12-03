#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>

using namespace std;

int cn, A1, A2, A3,B1, B2, B3,C1, C2, C3;
int vis[101][101][101];
string sss;

struct state{
    string s;
    int a,b,c,step;
    state(int aa, int bb, int cc, int st, string ss){
        a = aa;
        b = bb;
        c = cc;
        step = st;
        s = ss;
    }
};

int bfs(int a,int b,int c,int ta,int tb,int tc){
    queue<state>q;
    q.push(state(a,b,c,0,""));
    vis[a][b][c] = 1;
    while(!q.empty()){
        //printf("QUEUE: %d\n",q.size());
        state st = q.front();
        q.pop();
        if (st.a==ta&&st.b==tb&&st.c==tc){
            sss = st.s;
            return st.step;
        }
        int ra,rb,rc;
        if (st.a!=0){
            ra = st.a+A1-1;
            rb = st.b+A2;
            rc = st.c+A3;
            if (!(ra>100||rb>100||rc>100)&&!(ra<0||rb<0||rc<0)){
                if (!vis[ra][rb][rc]){
                    q.push(state(ra,rb,rc,st.step+1,st.s+"A"));
                    vis[ra][rb][rc] = 1;
                }
            }
        }
        //printf("MACHINE A\n");
        if (st.b!=0){
            ra = st.a+B1;
            rb = st.b+B2-1;
            rc = st.c+B3;
            if (!(ra>100||rb>100||rc>100)&&!(ra<0||rb<0||rc<0)){
                if (!vis[ra][rb][rc]){
                    q.push(state(ra,rb,rc,st.step+1,st.s+"B"));
                    vis[ra][rb][rc] = 1;
                }
            }
        }
        //printf("MACHINE B\n");
        if (st.c!=0){
            ra = st.a+C1;
            rb = st.b+C2;
            rc = st.c+C3-1;
            //printf("FOUND: %d %d %d\n",ra,rb,rc);
            if (!(ra>100||rb>100||rc>100)&&!(ra<0||rb<0||rc<0)){
              //  printf("Enter: %d %d %d\n",ra,rb,rc);
                if (!vis[ra][rb][rc]){
                //    printf("Vis: %d %d %d\n",ra,rb,rc);
                    q.push(state(ra,rb,rc,st.step+1,st.s+"C"));
                    vis[ra][rb][rc] = 1;
                }
                //else printf("ELSE\n");
            }
        }
        //printf("MACHINE C\n");
        if (st.a>=A1&&st.b>=A2&&st.c>=A3){
            ra = st.a-A1+1;
            rb = st.b-A2;
            rc = st.c-A3;
            if (!(ra<0||rb<0||rc<0)&&!(ra>100||rb>100||rc>100)){
                if (!vis[ra][rb][rc]){
                    q.push(state(ra,rb,rc,st.step+1,st.s+"a"));
                    vis[ra][rb][rc] = 1;
                }
            }
        }
       // printf("MACHINE a\n");
        if (st.a>=B1&&st.b>=B2&&st.c>=B3){
            ra = st.a-B1;
            rb = st.b-B2+1;
            rc = st.c-B3;
            if (!(ra<0||rb<0||rc<0)&&!(ra>100||rb>100||rc>100)){
                if (!vis[ra][rb][rc]){
                    q.push(state(ra,rb,rc,st.step+1,st.s+"b"));
                    vis[ra][rb][rc] = 1;
                }
            }
        }
        //printf("MACHINE b\n");
        if (st.a>=C1&&st.b>=C2&&st.c>=C3){
            ra = st.a-C1;
            rb = st.b-C2;
            rc = st.c-C3+1;
//            printf("FOUND: %d %d %d\n",ra,rb,rc);
            if (!(ra<0||rb<0||rc<0)&&!(ra>100||rb>100||rc>100)){
                if (!vis[ra][rb][rc]){
                    q.push(state(ra,rb,rc,st.step+1,st.s+"c"));
                    vis[ra][rb][rc] = 1;
                }
            }
        }
        //printf("MACHINE c\n");
    }
    return -1;
}

int main(){
    int t,x,y,sa,sb,sc,ea,eb,ec;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &x, &y);
        scanf("%d %d %d",&A1,&A2,&A3);
        scanf("%d %d %d",&B1,&B2,&B3);
        scanf("%d %d %d",&C1,&C2,&C3);
        printf("%d %d\n", x, y);
        for (int i=1;i<=y;i++){
            memset(vis,0,sizeof vis);
            scanf("%d %d %d %d %d %d %d",&cn,&sa,&sb,&sc,&ea,&eb,&ec);
            if (sa>100||sb>100||sc>100||ea>100||eb>100||ec>100)
                vis[-100][-100][-100] = 0;
            int tt = bfs(sa,sb,sc,ea,eb,ec);
            if (tt==-1){
                printf("%d NO SOLUTION\n",i);
            }
            else {
                printf("%d %d %s\n",i,tt,sss.c_str());
            }
        }
    }
}

/*
1
1 6
0 1 0
1 0 0
1 1 0
1 1000 1 1 0 2 1
2 1 1 1 2 0 1
3 1 1 1 2 2 0
4 1 1 1 2 0 1
5 1 1 1 0 2 1
6 1 1 1 0 0 2
*/

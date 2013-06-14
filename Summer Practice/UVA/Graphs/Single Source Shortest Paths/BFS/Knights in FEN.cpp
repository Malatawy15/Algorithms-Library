#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int dx[] = {-2, -2, 1, -1, 2, 2, 1, -1};
int dy[] = {1, -1, -2, -2, 1, -1, 2, 2};
string ideal;

typedef struct {
    int hx, hy, cost;
    string b;
} Board;

int inside_board(int x, int y){
    return x>=0&&y>=0&&x<5&&y<5;
}

int bfs (Board b){
    set<string> s;
    queue<Board> q;
    q.push(b);
    while(!q.empty()){
        Board bd = q.front();
        q.pop();
        if (bd.cost>10)
            break;
        if (ideal.compare(bd.b)==0)
            return bd.cost;
        if (s.count(bd.b)>0)
            continue;
        s.insert(bd.b);
        for (int i =0;i<8;i++){
            int nx = bd.hx+dx[i], ny = bd.hy+dy[i];
            if(inside_board(nx, ny)){
                Board nb;
                nb.b = bd.b;
                nb.hx = nx;nb.hy = ny;
                nb.b[bd.hx*5+bd.hy] = nb.b[nx*5+ny];
                nb.b[nx*5+ny] = ' ';
                nb.cost =bd.cost+1;
                q.push(nb);
            }
        }
    }
    return -1;
}

int main(){
    ideal = "111110111100 110000100000";
    int t;
    scanf("%d", &t);
    char s[222];
    gets(s);
    while(t--){
        Board b;
        b.b = "";
        char bb[5][5];
        for (int i=0;i<5;i++)
            gets(bb[i]);
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++){
                if (bb[i][j]==' '){
                    b.hx = i;
                    b.hy = j;
                }
                b.b+=bb[i][j];
            }
        b.cost = 0;
        int x = bfs(b);
        if (x==-1)
            printf("Unsolvable in less than 11 move(s).\n");
        else printf("Solvable in %d move(s).\n", x);
    }
}

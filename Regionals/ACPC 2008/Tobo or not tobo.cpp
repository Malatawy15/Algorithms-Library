#include<stdio.h>
#include<string.h>
#include<queue>
#include<set>
#include<string>

using namespace std;

#define Tobo pair<string, int>

char buf[10];
//char vis[9][9][9][9][9][9][9][9][9];
set<int> vis;
char cur, c1, c2, c3, c4;
string target = "123456789";
char stop [] = "0000000000";
int Y, tot;

typedef struct {
    int child[10];
} node;

vector<node> Trie;


int ins(int p, int nn){
    Trie[p].child[nn] = tot;
    node n;
    memset(n.child, -1, sizeof n.child);
    Trie.push_back(n);
    return tot++;
}

void ins (string s){
    int cur = 0, i;
    for (i=0;i<9;i++){
        if (Trie[cur].child[s[i]-'0']==-1)
            break;
        cur = Trie[cur].child[s[i]-'0'];
    }
    for (;i<9;i++){
        cur = ins(cur, s[i]-'0');
    }
}

int finder(string s){
    int cur = 0;
    for (int i=0;i<9;i++){
        if (Trie[cur].child[s[i]-'0']==-1)
            return 0;
        cur = Trie[cur].child[s[i]-'0'];
    }
    return 1;
}

int bfs(){
    tot = 0;
    queue<Tobo> q;
    string s = "";
    for (int i=1;i<10;i++)
        s+=buf[i];
    q.push(Tobo(s,0));
    Trie.clear();
    node n;
    memset(n.child, -1, sizeof n.child);
    Trie.push_back(n);
    tot++;
    //int st = 0;
    while(!q.empty()){
      //  st++;
        Tobo t = q.front();
        q.pop();
        if (t.second>Y)
            return -1;
        //if (vis[(t.first[0]-'0')-1][(t.first[1]-'0')-1][(t.first[2]-'0')-1][(t.first[3]-'0')-1][(t.first[4]-'0')-1][(t.first[5]-'0')-1][(t.first[6]-'0')-1][(t.first[7]-'0')-1][(t.first[8]-'0')-1]==cur)
          //  continue;
        //vis[(t.first[0]-'0')-1][(t.first[1]-'0')-1][(t.first[2]-'0')-1][(t.first[3]-'0')-1][(t.first[4]-'0')-1][(t.first[5]-'0')-1][(t.first[6]-'0')-1][(t.first[7]-'0')-1][(t.first[8]-'0')-1] = cur;
        if (t.first[0]=='1'&&t.first[1]=='2'&&t.first[2]=='3'&&t.first[3]=='4'&&t.first[4]=='5'&&t.first[5]=='6'&&t.first[6]=='7'&&t.first[7]=='8'&&t.first[8]=='9')
            return t.second;
        //printf("CHECK: %s %d\n", t.first.c_str(), st);

        //printf("PASS: %s\n", t.first.c_str());
        //A
        c1 = t.first[0];c2 = t.first[1];c3 = t.first[3];c4 = t.first[4];
        s = t.first;
        s[0] = c3; s[1] = c1; s[3] = c4; s[4] = c2;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        s = t.first;
        s[0] = c2; s[1] = c4; s[3] = c1; s[4] = c3;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        //B
        c1 = t.first[1];c2 = t.first[2];c3 = t.first[4];c4 = t.first[5];
        s = t.first;
        s[1] = c3; s[2] = c1; s[4] = c4; s[5] = c2;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        s = t.first;
        s[1] = c2; s[2] = c4; s[4] = c1; s[5] = c3;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        //C
        c1 = t.first[3];c2 = t.first[4];c3 = t.first[6];c4 = t.first[7];
        s = t.first;
        s[3] = c3; s[4] = c1; s[6] = c4; s[7] = c2;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        s = t.first;
        s[3] = c2; s[4] = c4; s[6] = c1; s[7] = c3;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        //D
        c1 = t.first[4];c2 = t.first[5];c3 = t.first[7];c4 = t.first[8];
        s = t.first;
        s[4] = c3; s[5] = c1; s[7] = c4; s[8] = c2;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
        s = t.first;
        s[4] = c2; s[5] = c4; s[7] = c1; s[8] = c3;
        if (!finder(s)){
        	q.push(Tobo(s,t.second+1));
        	ins(s);
        }
    }
    return -1;
}

int main(){
    cur = 'A';
    int cases = 1;
    scanf("%s", buf);
    while(strcmp(buf,stop)!=0){
        Y = buf[0]-'0';
        printf("%d. %d\n",cases++,bfs());
        scanf("%s", buf);
        cur++;
        vis.clear();
    }
}

#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<string>

using namespace std;

#define Tobo pair<string, int>

char buf[10];
//char vis[9][9][9][9][9][9][9][9][9];
//set<int> vis;
char cur, c1, c2, c3, c4;
string target = "123456789";
char stop [] = "0000000000";
int Y, tot;


typedef struct {
    int child[10];
    int tv;
} node;

node Trie[986412];
Tobo q[1000000];

int ins(int p, int nn){
    Trie[p].child[nn] = tot;
    node n;
    memset(n.child, -1, sizeof n.child);
    Trie[tot] = n;
    return tot++;
}

void ins (string s, int time){
    int cur = 0, i;
    for (i=0;i<9;i++){
        if (Trie[cur].child[s[i]-'0']==-1)
            break;
        cur = Trie[cur].child[s[i]-'0'];
    }
    for (;i<9;i++){
        cur = ins(cur, s[i]-'0');
    }
    Trie[cur].tv = time;
}

int finder(string s){
    int cur = 0;
    for (int i=0;i<9;i++){
        if (Trie[cur].child[s[i]-'0']==-1)
            return -1;
        cur = Trie[cur].child[s[i]-'0'];
    }
    return Trie[cur].tv;
}

int find_val(){
	string tar = "", s;
    for (int i=1;i<10;i++)
        tar+=buf[i];
    int cres = finder(tar);
    if (cres>-1){
        return cres>Y?-1:cres;
    }
    return -1;
}

int bfs(){
    string s;
    int num = 0, total = 1, r;
    while(num<total){
        Tobo t = q[num];
        r = t.second;
        //if (t.second>Y)
          //  return -1;
        //if (vis[(t.first[0]-'0')-1][(t.first[1]-'0')-1][(t.first[2]-'0')-1][(t.first[3]-'0')-1][(t.first[4]-'0')-1][(t.first[5]-'0')-1][(t.first[6]-'0')-1][(t.first[7]-'0')-1][(t.first[8]-'0')-1]==cur)
          //  continue;
        //vis[(t.first[0]-'0')-1][(t.first[1]-'0')-1][(t.first[2]-'0')-1][(t.first[3]-'0')-1][(t.first[4]-'0')-1][(t.first[5]-'0')-1][(t.first[6]-'0')-1][(t.first[7]-'0')-1][(t.first[8]-'0')-1] = cur;
       // if (tar.compare(t.first)==0)
         //   return t.second;
        //printf("CHECK: %s %d\n", t.first.c_str(), st);

        //printf("PASS: %s\n", t.first.c_str());

        num++;
        //A
        c1 = t.first[0];c2 = t.first[1];c3 = t.first[3];c4 = t.first[4];
        s = t.first;
        s[0] = c3; s[1] = c1; s[3] = c4; s[4] = c2;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[0] = c1, s[1] = c2, s[3] = c3, s[4] = c4;
        s[0] = c2; s[1] = c4; s[3] = c1; s[4] = c3;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[0] = c1, s[1] = c2, s[3] = c3, s[4] = c4;
        //B
        c1 = t.first[1];c2 = t.first[2];c3 = t.first[4];c4 = t.first[5];
        s = t.first;
        s[1] = c3; s[2] = c1; s[4] = c4; s[5] = c2;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[1] = c1, s[2] = c2, s[4] = c3, s[5] = c4;
        s[1] = c2; s[2] = c4; s[4] = c1; s[5] = c3;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[1] = c1, s[2] = c2, s[4] = c3, s[5] = c4;
        //C
        c1 = t.first[3];c2 = t.first[4];c3 = t.first[6];c4 = t.first[7];
        s[3] = c3; s[4] = c1; s[6] = c4; s[7] = c2;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[3] = c1, s[4] = c2, s[6] = c3, s[7] = c4;
        s[3] = c2; s[4] = c4; s[6] = c1; s[7] = c3;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[3] = c1, s[4] = c2, s[6] = c3, s[7] = c4;
        //D
        c1 = t.first[4];c2 = t.first[5];c3 = t.first[7];c4 = t.first[8];
        s[4] = c3; s[5] = c1; s[7] = c4; s[8] = c2;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
        s[4] = c1, s[5] = c2, s[7] = c3, s[8] = c4;
        s[4] = c2; s[5] = c4; s[7] = c1; s[8] = c3;
        if (finder(s)==-1){
        	q[total++]=(Tobo(s,t.second+1));
        	ins(s,t.second+1);
        }
    }
    //printf("TOTAL %d\n", r);
    return -1;
}

int main(){
    tot = 0;
    node n;
    memset(n.child, -1, sizeof n.child);
    Trie[tot] = n;
    tot++;
    q[0] = (Tobo("123456789",0));
    ins("123456789", 0);
    cur = 'A';
    int cases = 1;
    bfs();
    //printf("%d\n", Trie.size());
    scanf("%s", buf);
    while(buf[1]!='0'){
        Y = buf[0]-'0';
        printf("%d. %d\n",cases++,find_val());
        scanf("%s", buf);
        cur++;
    }
}

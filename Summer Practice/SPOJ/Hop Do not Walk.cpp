#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<set>
#include<queue>

using namespace std;

#define Frog pair<string, int>

int check(string s){
    int bs = 0, be = 0;
    for (int i=0;i<s.size();i++)
        if (s[i]=='B'){
            if (!bs)
                bs = 1;
            else if (bs&&be)
                return 0;
        }
        else if (s[i]=='W')
            if (bs)
                be = 1;
    return 1;
}

int bfs(string sc){
    if (sc.size()<3)
        return 0;
    set<string> vis;
    queue<Frog> q;
    q.push(Frog(sc,0));
    while(!q.empty()){
        Frog f = q.front();
        q.pop();
        if (vis.count(f.first)>0)
            continue;
        if (check(f.first))
            return f.second;
        vis.insert(f.first);
        if (f.second==9)
            continue;
        int fp;
        for (int i=0;i<f.first.size();i++)
            if (f.first[i]=='F'){
                fp = i;
                break;
            }
        if (fp!=0){
            string s1 = f.first;
            s1[fp] = s1[fp-1];
            s1[fp-1] = 'F';
            q.push(Frog(s1,f.second+1));
        }
        if (fp!=f.first.size()-1){
            string s1 = f.first;
            s1[fp] = s1[fp+1];
            s1[fp+1] = 'F';
            q.push(Frog(s1,f.second+1));
        }
        if (fp>1){
            string s1 = f.first;
            s1[fp] = (s1[fp-2]=='B'?'W':'B');
            s1[fp-2] = 'F';
            q.push(Frog(s1,f.second+1));
        }
        if (fp<f.first.size()-2){
            string s1 = f.first;
            s1[fp] = (s1[fp+2]=='B'?'W':'B');
            s1[fp+2] = 'F';
            q.push(Frog(s1,f.second+1));
        }
    }
    return -1;
}

int main(){
    string s;
    int cs=1;
    while(1){
        cin>>s;
        if (s[0]=='-')
            break;
        printf("%d. %d\n",cs++,bfs(s));
    }
}

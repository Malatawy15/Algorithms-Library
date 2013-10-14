#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> graph[10];
int vis[10][10][10][10][1025];
int cn;

struct state{
    vector<int> pos;
    int bitmask, depth;
    bool operator<(const state& s) const{
        return depth<s.depth;
    }
};

int S, N, P;

int bfs(){
    cn++;
    queue<state> q;
    state ss;
    ss.depth = 0;
    for (int i=0;i<N;i++)
        ss.pos.push_back(0);
    ss.bitmask = 1;
    q.push(ss);
    //set<state> vis;
    int target = 0, cur;
    for (int i=0;i<S;i++)
        target|=(1<<i);
    while(!q.empty()){
        state s = q.front();
        q.pop();
        //printf("STEP: %d %d\n", s.bitmask, s.depth);
        if (s.bitmask==target)
            return s.depth;
        //if ((vis.insert(s)).second==true)
          //  continue;

        if (N==1){
            cur = s.pos[0];
            //if (vis[cur][0][0][0][s.bitmask]==cn)
              //  continue;
            for (int i=0;i<graph[cur].size();i++){
                state s1;
                s1.depth = s.depth+1;
                s1.bitmask = s.bitmask|(1<<graph[cur][i]);
                if (vis[graph[cur][i]][0][0][0][s1.bitmask]==cn)
                	continue;
               	vis[graph[cur][i]][0][0][0][s1.bitmask]=cn;
                s1.pos.push_back(graph[cur][i]);
                if (s1.bitmask==target)
            return s1.depth;
                q.push(s1);
            }
        }
        else if (N==2){
            int cur1 = s.pos[0], cur2 = s.pos[1];
            //if (vis[cur1][cur2][0][0][s.bitmask]==cn)
              //  continue;
            for (int i=0;i<graph[cur1].size();i++)
                for (int j=0;j<graph[cur2].size();j++){
                    state s1;
                    s1.depth = s.depth+1;
                    s1.bitmask = s.bitmask|(1<<graph[cur1][i]);
                    s1.bitmask |= s.bitmask|(1<<graph[cur2][j]);
                    s1.pos.push_back(graph[cur1][i]);
                    s1.pos.push_back(graph[cur2][j]);
                    sort(s1.pos.begin(), s1.pos.end());
                    if (s1.bitmask==target)
            return s1.depth;
                    if (vis[s1.pos[0]][s1.pos[1]][0][0][s1.bitmask]==cn)
                		continue;
                		vis[s1.pos[0]][s1.pos[1]][0][0][s1.bitmask] = cn;
                    q.push(s1);
                }
        }
        else if (N==3){
            int cur1 = s.pos[0], cur2 = s.pos[1], cur3 = s.pos[2];
            //if (vis[cur1][cur2][cur3][0][s.bitmask]==cn)
              //  continue;
            for (int i=0;i<graph[cur1].size();i++)
                for (int j=0;j<graph[cur2].size();j++)
                    for (int k=0;k<graph[cur3].size();k++){
                    	//if ((s.bitmask&(1<<graph[cur1][i])>0)&&(s.bitmask&(1<<graph[cur2][j])>0)&&(s.bitmask&(1<<graph[cur3][k])>0))
                          //  	continue;
                        state s1;
                        s1.depth = s.depth+1;
                        s1.bitmask = s.bitmask|(1<<graph[cur1][i]);
                        s1.bitmask |= s.bitmask|(1<<graph[cur2][j]);
                        s1.bitmask |= s.bitmask|(1<<graph[cur3][k]);
                        s1.pos.push_back(graph[cur1][i]);
                        s1.pos.push_back(graph[cur2][j]);
                        s1.pos.push_back(graph[cur3][k]);
                        if (s1.bitmask==target)
            return s1.depth;
                        sort(s1.pos.begin(), s1.pos.end());
                        if (vis[s1.pos[0]][s1.pos[1]][s1.pos[2]][0][s1.bitmask]==cn)
                		continue;
                		vis[s1.pos[0]][s1.pos[1]][s1.pos[2]][0][s1.bitmask] = cn;
                        q.push(s1);
                    }
        }
        else if (N==4){
            int cur1 = s.pos[0], cur2 = s.pos[1], cur3 = s.pos[2], cur4 = s.pos[3];
            //if (vis[cur1][cur2][cur3][cur4][s.bitmask]==cn)
              //  continue;
            for (int i=0;i<graph[cur1].size();i++)
                for (int j=0;j<graph[cur2].size();j++)
                    for (int k=0;k<graph[cur3].size();k++)
                        for (int l=0;l<graph[cur4].size();l++){
                            //if (graph[cur1][i]==1 &&graph[cur2][j]==1&&graph[cur3][k]==2&&graph[cur4][l]==3)
                            //printf("INS: %d %d %d %d %d\n",graph[cur1][i],graph[cur2][j],graph[cur3][k],graph[cur4][l], s.depth);
                            //if ((s.bitmask&(1<<graph[cur1][i])>0)&&(s.bitmask&(1<<graph[cur2][j])>0)&&(s.bitmask&(1<<graph[cur3][k])>0)&&(s.bitmask&(1<<graph[cur4][l])>0))
                            	//continue;
                            state s1;
                            s1.depth = s.depth+1;
                            s1.bitmask = 0;
                            s1.bitmask |= s.bitmask|(1<<graph[cur1][i]);
                            s1.bitmask |= s.bitmask|(1<<graph[cur2][j]);
                            s1.bitmask |= s.bitmask|(1<<graph[cur3][k]);
                            s1.bitmask |= s.bitmask|(1<<graph[cur4][l]);
                            //if (graph[cur1][i]==1 &&graph[cur2][j]==1&&graph[cur3][k]==2&&graph[cur4][l]==3)
                            //printf("INS: %d %d %d %d %d %d %d\n",graph[cur1][i],graph[cur2][j],graph[cur3][k],graph[cur4][l], s.depth, s.bitmask,s1.bitmask);
                		//vis[graph[cur1][i]][graph[cur2][j]][graph[cur3][k]][graph[cur4][l]][s1.bitmask] = cn;
                		if (s1.bitmask==target)
            return s1.depth;
                            s1.pos.push_back(graph[cur1][i]);
                            s1.pos.push_back(graph[cur2][j]);
                            s1.pos.push_back(graph[cur3][k]);
                            s1.pos.push_back(graph[cur4][l]);
                            sort(s1.pos.begin(), s1.pos.end());
                            if (vis[s1.pos[0]][s1.pos[1]][s1.pos[2]][s1.pos[3]][s1.bitmask]==cn)
                		continue;
                		vis[s1.pos[0]][s1.pos[1]][s1.pos[2]][s1.pos[3]][s1.bitmask] = cn;
                            q.push(s1);
                        }
        }
    }
}

int main(){
    cn=0;
    char buf[10];
    scanf("%d", &S);
    while(S){
        scanf("%d %d", &N, &P);
        for (int i=0;i<P;i++){
            scanf("%s", buf);
            graph[buf[0]-'A'].push_back(buf[1]-'A');
            graph[buf[1]-'A'].push_back(buf[0]-'A');
            //printf("INP: %s\n", buf);
        }
        printf("%d\n", bfs());
        for (int i=0;i<S;i++){
            graph[i].clear();
        }
        scanf("%d", &S);
    }
}

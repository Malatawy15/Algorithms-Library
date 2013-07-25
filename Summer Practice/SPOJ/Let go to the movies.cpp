#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>
#include<queue>

using namespace std;
#define INF 100100

int F, S;
vector<int>graph[100010];
vector<int>levels[100010];
int hp[100010];


map<string, int> nti;
map<string, int>::iterator it;

int dp[100010][2][2];


int bfs(int s){
    queue<pair<int,int> >q;
    q.push(make_pair(s,0));
    int level = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        //printf("%d %d\n", p.first, p.second);
        levels[p.second].push_back(p.first);
        level = p.second;
        for (int i=0;i<graph[p.first].size();i++)
            q.push(make_pair(graph[p.first][i],level+1));
    }
    return level;
}

void minimize(int level){
    //printf("START: %d\n", level);
    for (int k=level;k>=0;k--){
        //printf("CURRENT LEVEL: %d\n", k);
        for (int j=0;j<levels[k].size();j++){
            int fs = 0, ff = 0, ss = 0, sf = 0, cn, n;
            long long cost_f = 0LL, cost_s = 0LL;
            n = levels[k][j];

            for (int i=0;i<graph[n].size();i++){
                cn = graph[n][i];
                fs += dp[cn][0][0];
                ff += dp[cn][0][1];
                ss += dp[cn][1][0];
                sf += dp[cn][1][1];
            }
            //ana included fe family ticket
            cost_s = ss*S+sf*F;
            cost_f = fs*S+(ff+1)*F;
            if (cost_s<cost_f){
                dp[n][0][0] = ss;
                dp[n][0][1] = sf;
            }
            else if (cost_s>cost_f){
                dp[n][0][0] = fs;
                dp[n][0][1] = ff+1;
            }
            else if (ss+sf<=fs+ff+1){
                dp[n][0][0] = ss;
                dp[n][0][1] = sf;
            }
            else{
                dp[n][0][0] = fs;
                dp[n][0][1] = ff+1;
            }
            //ana msh included fe family ticket
            cost_s = (ss+1)*S+sf*F;
            if (cost_s<cost_f){
                dp[n][1][0] = ss+1;
                dp[n][1][1] = sf;
            }
            else if (cost_s>cost_f){
                dp[n][1][0] = fs;
                dp[n][1][1] = ff+1;
            }
            else if (ss+1+sf<=fs+ff+1){
                dp[n][1][0] = ss+1;
                dp[n][1][1] = sf;
            }
            else {
                dp[n][1][0] = fs;
                dp[n][1][1] = ff+1;
            }
            //printf("NODE COUNT: %d %d %d %d %d\n", n,dp[n][0][0],dp[n][0][1],dp[n][1][0],dp[n][1][1]);
        }
    }
}
char inp[100000000];
int main(){
    //freopen("movies.in","r",stdin);
    //freopen("movies_out.txt","w",stdout);
    int ind = 0, ind1, ind2, cases = 0, max_level = -1;
    char *st;
    string s;
    gets(inp);
    while(true){
        sscanf(inp,"%d %d",&S, &F);
        ind = 0;
        if (S==0&&F==0)
            break;
        memset(hp,0,sizeof hp);
        while(true){
            gets(inp);
            while(!strcmp(inp,""))
                gets(inp);
            if (inp[0]>='0'&&inp[0]<='9')
                break;
            st = strtok (inp," \r\t\n");
            s = "";
            for (int l =0;l<strlen(st);l++)
                if (st[l]!='\\')
                    s+=st[l];
                else break;
            it = nti.find(s);
            if (it==nti.end()){
                ind1 = ind++;
                //printf("MAP INS: %s %d\n", st, ind1);
                nti.insert(make_pair(s, ind1));
            }
            else{
                ind1 = (*it).second;
                //printf("MAP INDEX: %d\n",ind1);
            }
            st = strtok (NULL," \r\t\n");
            while (st!=NULL){
                if (!strcmp(st,"\r\n")||!strcmp(st,"\r")||!strcmp(st,"\n")){
                    st = strtok (NULL," \r \t \n");
                    continue;
                }
                s = "";
                for (int l =0;l<strlen(st);l++)
                    if (st[l]!='\\')
                        s+=st[l];
                    else break;
                //printf("%s\n",s.c_str());
                it = nti.find(s);
                if (it==nti.end()){
                    ind2 = ind++;
                    //printf("MAP INS: %s %d\n", st, ind2);
                    nti.insert(make_pair(s, ind2));
                }
                else ind2 = (*it).second;
                //printf("INSERT: %d %d\n",ind1, ind2);
                graph[ind1].push_back(ind2);
                hp[ind2] = 1;
                st = strtok (NULL," \r \t \n");
            }
        }
        //printf("Ind: %d\n",ind);
        int level = -1,tmp;
        for (int i=0;i<ind;i++)
            if (!hp[i]){
                tmp = bfs(i);
                level = max(level, tmp);
            }
        /*if (cases==65){
        printf("IND: %d\n", ind);
        printf("BFS DONE = %d\n",level);
        for (int i=0;i<=level;i++){
            printf("Level #%d: ",i);
            for (int j=0;j<levels[i].size();j++)
                printf("%d ",levels[i][j]);
            printf("\n");
        }
        }*/
        memset(dp,0,sizeof dp);
        minimize(level);
        int sc = 0, fc = 0, cn;
        for (int i=0;i<levels[0].size();i++){
            cn = levels[0][i];
            sc+=dp[cn][1][0];
            fc+=dp[cn][1][1];
            //printf("%d %d %d\n",cn,sc,fc);
        }
        long long res = 0LL;
        res = sc*S+fc*F;
        printf("%d. %d %d %ld\n",++cases,sc,fc,res);
        for (int i=0;i<ind+1;i++){
            graph[i].clear();
            levels[i].clear();
        }
        max_level = max(max_level,level);
        nti.clear();
    }
    //printf("MAX LEVEL: %d\n", max_level);

}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define Point pair<int, int>
char grid[110][110];
/*
int vis[110][110][110];
int numb[110][110][110];
*/
int R, C, maxi;
/*
void dp(int r, int c1, int c2, int pre, int num){
    //printf("%d %d %d %d %d\n", r,c1,c2,pre,num);
    if (r==R-1&&c1==C-1&&c2==C-1){
        maxi = max(maxi, pre+num);
        return;
    }
    if (grid[r][c1]=='#'||grid[r][c2]=='#')
        return;
    if (vis[r][c1][c2]>pre)
        return;
    else if(vis[r][c1][c2]==pre&&numb[r][c1][c2]>num)
        return;
    else if (vis[r][c1][c2]==pre&&numb[r][c1][c2]==num&&num==0)
    return;
    int add;
    if (c1!=c2)
        add = (grid[r][c1]=='*'?1:0)+(grid[r][c2]=='*'?1:0);
    else add = (grid[r][c1]=='*'?1:0);
    char ch1 = grid[r][c1], ch2 = grid[r][c2];
    int n1 = (grid[r][c1]=='*'?1:0), n2 = (grid[r][c2]=='*'?1:0);
    grid[r][c1]='.';
    grid[r][c2]='.';
    vis[r][c1][c2] = pre;
    numb[r][c1][c2] = num;
    if (c1==c2){
        if (c2!=C-1){
     //       printf("CALL DIFF1\n");
            dp(r, c1, c2+1, pre+n1, num);
        }
    }
    else {
        if (c2!=C-1){
       //     printf("CALL DIFF2\n");
            dp(r, c1, c2+1, pre+n1, num+n2);
        }
        if (c1!=C-1){
         //   printf("CALL DIFF3\n");
            dp(r, c1+1, c2, pre+n1, num+n2);
        }
    }
    if (r!=R-1){
        //printf("CALL DIFF4\n");
        dp(r+1, c1, c2, pre+num+add,0);
    }
    grid[r][c1]=ch1;
    grid[r][c2]=ch2;
}
*/
int dp[110][110][210][2];
int maximize(int r1, int r2, int stp){
    if (stp==R+C-2){
        if (r1==R-1&&r2==R-1)
            return grid[R-1][C-1]=='*'?1:0;
        else return -1;
    }
    if (dp[r1][r2][stp][1]!=0)
        return dp[r1][r2][stp][0];
    dp[r1][r2][stp][1] = 1;
    int c1 = stp-r1, c2 = stp-r2, ret = -1;
    if (c1<C&&c2<C&&grid[r1][c1]!='#'&&grid[r2][c2]!='#'){
        ret = max(ret, maximize(r1,r2,stp+1));
        if (r1+1<R)
            ret = max(ret, maximize(r1+1,r2,stp+1));
        if (r2+1<R)
            ret = max(ret, maximize(r1,r2+1,stp+1));
        if (r1+1<R&&r2+1<R)
            ret = max(ret, maximize(r1+1,r2+1,stp+1));
    }
    if (ret!=-1){
        if ((r1!=r2)||(c1!=c2)){
            ret+=(grid[r1][c1]=='*');
            ret+=(grid[r2][c2]=='*');
        }
        else ret+=(grid[r2][c2]=='*');
    }
    return dp[r1][r2][stp][0] = ret;
}



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&C,&R);
        for (int i=0;i<R;i++)
            scanf("%s",grid[i]);
        //printf("READ DONE\n");
        //maxi = -1;
        //memset(vis,-1,sizeof vis);
        //memset(numb,-1,sizeof numb);
        memset(dp,0,sizeof dp);
        //printf("MEM DONE\n");
        //dp(0,0,0,0,0);
        /*
        dp[0][0][0][0] = grid[0][0]=='*'?1:0;
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++){
                if (grid[i][j]=='#')
                    continue;
                for (int k=0;k<C;k++){
                    if (grid[i][k]=='#')
                        continue;
                    if (i!=0&&grid[i-1][j]!='#'&&grid[i-1][k]!='#'){
                        int num = dp[i-1][j][k][0];
                        if (j==k){
                            num+=(grid[i][j]=='*'?1:0);
                        }
                        else{
                            num+=((grid[i][j]=='*'?1:0)+(grid[i][k]=='*'?1:0));
                        }
                        if (num>dp[i][j][k][0]){
                            dp[i][j][k][0] = num;
                            dp[i][j][k][1] = k;
                        }
                        else if (num==dp[i][j][k][0]&&k>dp[i][j][k][1]){
                            dp[i][j][k][1] = k;
                        }
                    }
                    if (j!=0&&grid[i][j-1]!='#'){
                        int num = dp[i][j-1][k][0];
                        //if (j<dp[i][j-1][k][1])
                            num+=(grid[i][j]=='*'?1:0);
                        if (num>dp[i][j][k][0]){
                            dp[i][j][k][0] = num;
                            dp[i][j][k][1] = dp[i][j-1][k][1];
                        }
                        else if (num==dp[i][j][k][0]&&dp[i][j-1][k][1]>dp[i][j][k][1]){
                            dp[i][j][k][1] = dp[i][j-1][k][1];
                        }
                    }
                    if (k!=0&&grid[i][k-1]!='#'){
                        int num = dp[i][j][k-1][0];
                        num+=(grid[i][k]=='*'?1:0);
                        if (num>dp[i][j][k][0]){
                            dp[i][j][k][0] = num;
                            dp[i][j][k][1] = dp[i][j][k-1][1];
                        }
                        else if (num==dp[i][j][k][0]&&dp[i][j][k-1][1]>dp[i][j][k][1]){
                            dp[i][j][k][1] = dp[i][j][k-1][1];
                        }
                    }
                    //if (j<dp[i][j][k][1]){
                        //printf("Here: %d %d %d %d\n", i, j, k,dp[i][j][k][1]);
                      //  dp[i][j][k][0]+=(grid[i][j]=='*'?1:0);
                    //}
                    //dp[i][j][k][0]+=(grid[i][k]=='*'?1:0);
                }
            }
        /*printf("MATRIX:\n");
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                for (int k=0;k<C;k++)
                    printf("(%d, %d) ", dp[i][j][k][0], dp[i][j][k][1]);
                printf("\n");
            }
            printf("\n\n");
        }*/
        printf("%d\n",maximize(0,0,0));
    }
}


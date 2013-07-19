#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

char a[100];
char b[100];
char ps[100];
int sa, sb;
int lcs_len[85][85];


int lcs(int x, int y){
    if (x==sa||y==sb)
        return lcs_len[x][y] = 0;
    if (lcs_len[x][y]!=-1) return lcs_len[x][y];
    lcs_len[x][y] = 0;
    if (a[x]==b[y])
        return lcs_len[x][y] = 1+lcs(x+1,y+1);
    return lcs_len[x][y] = max(lcs(x+1,y), lcs(x,y+1));
}


void re_construct(int x, int y, int len){
    if (len==lcs_len[0][0]){
        ps[len] = 0;
    	puts(ps);
		return;
    }
    if (x==sa||y==sb)
        return;
    int flag = 0;
    for (char c = 'a'; c<='z';c++){
        flag = 0;
        for (int i = x;i<sa;i++){
            if (a[i]!=c)
                continue;
            for (int j=y;j<sb;j++){
                if (b[j]==c&&lcs(i,j)==lcs_len[0][0]-len){
                    ps[len] = c;
                    re_construct(i+1,j+1,len+1);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }
}

void printAll(int na, int nb, int d) {
    if(d==lcs_len[0][0]) {
		ps[d] = 0;
		puts(ps);
		return;
	}
	if(na==sa || nb==sb) return;
	for(char ch='a'; ch<='z'; ch++) {
		bool done = false;
		for(int i=na; i<sa; i++) {
			if(ch==a[i]) {
				for(int j=nb; j<sb; j++) {
					if(ch==b[j] && lcs(i, j)==lcs_len[0][0]-d) {
						ps[d] = ch;
						printAll(i+1, j+1, d+1);
						done = true;
						break;
					}
				}
			}
			if(done) break;
		}
	}
}

int main(){
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        scanf("%s",b);
        sa = strlen(a);
        sb = strlen(b);
        for(int i=0; i<sa; i++)
    		for(int j=0; j<sb; j++)
				lcs_len[i][j] = -1;
        lcs(0, 0);
        re_construct(0,0,0);
        //printf("%d\n", lcs_len[0][0]);
        //printAll(0, 0, 0);
        if (t)
            printf("\n");
    }
}

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main(){
    char buf [15];
    scanf("%s", buf);
    vector<int> av;
    for (int i=1;i<=10;i++)
        if (buf[i-1]=='1')
            av.push_back(i);
    int M, wr = 0, wl = 0, l = -1, pos = 1, i;
    scanf("%d", &M);
    vector<int> res;
    for (int j=0;j<M;j++){
        if (j%2){
            for (i=0;i<av.size();i++){
                if (l!=av[i]&&wr+av[i]>wl){
                    l = av[i];
                    wr+=av[i];
                    res.push_back(l);
                    break;
                }
            }
            if (i==av.size()){
                pos = 0;
                break;
            }
        }
        else{
            for (i=0;i<av.size();i++){
                if (l!=av[i]&&wl+av[i]>wr){
                    l = av[i];
                    wl+=av[i];
                    res.push_back(l);
                    break;
                }
            }
            if (i==av.size()){
                pos = 0;
                break;
            }
        }
    }
    if (pos){
        printf("YES\n");
        printf("%d", res[0]);
        for (int j=1;j<res.size();j++)
            printf(" %d", res[j]);
        printf("\n");
    }
    else printf("NO\n");
}

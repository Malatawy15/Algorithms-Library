#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    char num[101];
    while(t--){
        string nn = "";
        scanf("%s", num);
        int maxi = -1,strl = strlen(num), ns;
        for (int i=0;i<strl-1;i++){
            nn+=num[i];
            maxi = max(maxi, num[i]-'0');
            if (num[i]>num[i+1]){
                for (char c = num[i]-1;c>num[i+1];c--){
                    nn+=c;
                }
            }
            else if (num[i]<num[i+1]){
                for (char c = num[i]+1;c<num[i+1];c++){
                    nn+=c;
                }
            }
        }
        nn+=num[strl-1];
        maxi = max(maxi, num[strl-1]-'0');
        ns = nn.size();
        char grid[maxi][ns+1];
        for (int i=0;i<ns;i++){
            for (int j = 1;j<=maxi;j++){
                if (j<=(nn[i]-'0'))
                    grid[maxi-j][i] = '+';
                else grid[maxi-j][i] = '*';
            }
        }
        for (int i=0;i<maxi;i++){
            grid[i][ns] = '\0';
            printf("%s\n", grid[i]);
        }
    }
}

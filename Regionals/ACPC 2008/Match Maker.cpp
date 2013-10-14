#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main(){
    regex_t regex;
    char pat[100005];
    char inp[100005];
    const char* c1;
    int cn = 0, cnn = 1;
    while(true){
        scanf("%s", pat);
        string s = "^";
        int i = 0;
        for (;i<strlen(pat);i++){
            if (pat[i]=='*'){
                s+=("\\([0-9][0-9]\\)*");
            }
            else if (pat[i]=='#'){
                s+=("[0-9]\\([0-9][0-9]\\)*");
            }
            else{
                s+=pat[i];
            }
        }
        s+="$";
        cn++;
        cnn = 1;
        c1 = s.c_str();
        //printf("PAT: %s\n", c1);
        scanf("%s", inp);
        regcomp(&regex, c1, 0);
        while(strcmp(inp,"QUIT")!=0&&strcmp(inp,"END")!=0){
            //printf("INP: %s\n", inp);
            if (regexec(&regex, inp, 0, NULL, 0)==0)
                printf("%d.%d. match\n",cn,cnn);
            else printf("%d.%d. not\n",cn,cnn);
            scanf("%s", inp);
            cnn++;
        }
        if (!strcmp(inp,"QUIT"))
            break;
    }

}

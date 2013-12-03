#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>

using namespace std;

char vow[] = {'a','i', 'y', 'e', 'o', 'u'};
char car[] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

int main(){
    map<char,int> vows;
    map<char,int> cars;
    map<char,int>::iterator it;
    for (int i=0;i<6;i++)
        vows.insert(make_pair(vow[i],i));
    for (int i=0;i<20;i++)
        cars.insert(make_pair(car[i],i));
    char buf [1000];
    while(gets(buf)){
        int ss = strlen(buf);
        char res[1000];
        for (int i=0;i<ss;i++){
            if (!(buf[i]>='A'&&buf[i]<='Z')&&!(buf[i]>='a'&&buf[i]<='z')){
                res[i] = buf[i];
                continue;
            }
            int f = 0;
            if (buf[i]>='A'&&buf[i]<='Z'){
                f = 1;
                buf[i] = (char) (32+buf[i]);
            }
            it = vows.find(buf[i]);
            if (it!=vows.end()){
                res[i] = vow[((it->second)+3)%6];
            }
            else {
                it = cars.find(buf[i]);
                res[i] = car[((it->second)+10)%20];
            }
            if (f){
                res[i] = (char) (res[i]-32);
            }
        }
        res[ss] = '\0';
        printf("%s\n", res);
    }
}

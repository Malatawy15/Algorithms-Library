#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define Pair pair<int, int>

string seq;
char buf[10010];

map<Pair, int> dp;
map<Pair, int>::iterator it;

multiset <string> ms;
map<char, string> ctm;

void populate(){
    ctm.insert(make_pair('A',".-"));
    ctm.insert(make_pair('B',"-..."));
    ctm.insert(make_pair('C',"-.-."));
    ctm.insert(make_pair('D',"-.."));
    ctm.insert(make_pair('E',"."));
    ctm.insert(make_pair('F',"..-."));
    ctm.insert(make_pair('G',"--."));
    ctm.insert(make_pair('H',"...."));
    ctm.insert(make_pair('I',".."));
    ctm.insert(make_pair('J',".---"));
    ctm.insert(make_pair('K',"-.-"));
    ctm.insert(make_pair('L',".-.."));
    ctm.insert(make_pair('M',"--"));
    ctm.insert(make_pair('N',"-."));
    ctm.insert(make_pair('O',"---"));
    ctm.insert(make_pair('P',".--."));
    ctm.insert(make_pair('Q',"--.-"));
    ctm.insert(make_pair('R',".-."));
    ctm.insert(make_pair('S',"..."));
    ctm.insert(make_pair('T',"-"));
    ctm.insert(make_pair('U',"..-"));
    ctm.insert(make_pair('V',"...-"));
    ctm.insert(make_pair('W',".--"));
    ctm.insert(make_pair('X',"-..-"));
    ctm.insert(make_pair('Y',"-.--"));
    ctm.insert(make_pair('Z',"--.."));
}

void decode(){
    int size = strlen(buf);
    string ret = "";
    for (int i=0;i<size;i++){
        ret+=(ctm.find(buf[i])->second);
    }
    //printf("INS: %s\n", ret.c_str());
    ms.insert(ret);
}

int count(int x, int y){
    if (x==y){
        return ms.count(seq[x]+"");
    }
    it = dp.find(Pair(x,y));
    if (it!=dp.end())
        return it->second;
    int sum = ms.count(seq.substr(x,y-x+1));
    for (int i=x;i<y;i++){
        sum+=(count(x,i)*count(i+1,y));
    }
    dp.insert(make_pair(Pair(x,y),sum));
    //printf("%d %d: %d\n",x,y,sum);
    return sum;
}

int main(){
    populate();
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%s", buf);
        seq = string(buf);
        scanf("%d", &n);
        for (int i=0;i<n;i++){
            scanf("%s", buf);
            decode();
        }
        dp.clear();
        printf("%d\n",count(0,seq.size()-1));
        ms.clear();
    }
}

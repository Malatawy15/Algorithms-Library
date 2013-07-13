#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
#define ST pair <double,pair<int,int> >
#define mp(a,b,c) make_pair (a,make_pair(b,c) )
#define votes first
#define id second.first
#define div second.second
#define EPS 1e-9;

int ind,N,S;
int vals [10010];


int dhondt(){
    priority_queue <ST> pq;
    for (int i =0;i<N;i++)
        pq.push(mp(vals[i],N-i,1));
    int sum=0;
    for (int i =0;i<S;i++){
        ST st = pq.top();
        pq.pop();
        if (N-st.id==ind)
            sum++;
        st.div++;
        st.votes=(vals[N-st.id]*1.0)/(st.div*1.0);
        pq.push(st);
    }
    return sum;
}

int saintl(){
    priority_queue <ST> pq;
    for (int i =0;i<N;i++)
        pq.push(mp(vals[i],N-i,0));
    int sum=0;
    for (int i =0;i<S;i++){
        ST st = pq.top();
        pq.pop();
        if (N-st.id==ind)
            sum++;
        st.div++;
        st.votes= vals[N-st.id]/(2.0*st.div+1);
        pq.push(st);
    }
    return sum;
}

int main(){
    int t,c=1;
    scanf("%d",&t);
    char names[50];
    char nums[50];
    while(t--){
        scanf("%d %d",&N,&S);
        for (int i =0;i<N;i++){
            scanf("%s %s",names,nums);
            vals[i]=0;
            for (int j =0;j<strlen(nums);j++){
                if (nums[j]>='0'&&nums[j]<='9')
                    vals[i]=vals[i]*10+(nums[j]-'0');
            }
            if (!strcmp(names,"ACM"))
                ind = i;
        }
        int d = dhondt(), s = saintl();
        if (d==s)
            printf("Case %d: No difference\n",c++);
        else if (d>s)
            printf("Case %d: D\n",c++);
        else printf("Case %d: S\n",c++);
    }
}


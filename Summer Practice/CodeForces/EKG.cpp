#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int N, X, S;
int nums [1010];
int pset [1010];
int set_size[1010];
set<int> positions;

int find_set(int p){
   return pset[p] = pset[p]?pset[p]: find_set(nums[p]);
}

int find_pos(int p){
    return nums[p]==0?1:1+find_pos(nums[p]);
}
/*
void permute(int off, vector<vector<int> > last){
    if (off==S-1)
        return;
    vector<vector<int> > newv;
    if (off==1){
        for (int i = 1;i<=S;i++)
            if (i!=pset[X]){
                vector<int> v;
                v.push_back(i);
                newv.push_back(v);
                positions.insert(set_size[i]);
            }
    }
    else{
        for (int i =1;i<=S;i++){
            if (i!=pset[X]){
                for (int j =0;j<last.size();j++){
                    if (find(last[j].begin(), last[j].end(), i) == last[j].end()){
                        vector<int> v(last[j].begin(), last[j].end());
                        int sum = 0;
                        v.push_back(i);
                        for (int k =0;k<v.size();k++)
                            sum+=set_size[v[k]];
                        positions.insert(sum);
                        newv.push_back(v);
                    }
                }
            }
        }
    }
    permute(off+1, newv);
}
*/
int main(){
    scanf("%d %d", &N, &X);
    memset(pset, 0, sizeof pset);
    memset(set_size, 0, sizeof set_size);
    for (int i =1;i<=N;i++){
        scanf("%d", &nums[i]);
        if (nums[i]==0){
            pset[i] = ++S;
        }
    }
    if (S==0||S==1){
        printf("%d\n", find_pos(X));
        return 0;
    }
    for (int i =1;i<=N;i++){
        if (!pset[i])
            find_set(i);
        set_size[pset[i]]++;
    }
    int pos = find_pos(X);
    //printf("S: %dSet: %d\n",S, pset[X]);
    /*printf("%d\n", pos);
    vector<vector<int> > v;
    permute(1, v);
    set<int>::iterator it;
    for (it=positions.begin(); it!=positions.end(); ++it)
        printf("%d\n", (*it)+pos);
    for (int i =1;i<=S;i++)
        if (i!=pset[X])
            pos+=set_size[i];
    printf("%d\n", pos);*/
    vector<int> v;
    vector<int>::iterator it, it1;
    for (int i =1;i<=S;i++)
        v.push_back(i);
    do {
        it = find(v.begin(), v.end(), pset[X]);
        int sum = 0;
        for (it1=v.begin();it1!=it;++it1)
            sum+=set_size[*it1];
        positions.insert(sum+pos);
    } while ( next_permutation(v.begin(),v.end()) );
    set<int>::iterator it2;
    for (it2=positions.begin(); it2!=positions.end(); ++it2)
        printf("%d\n", (*it2));
}

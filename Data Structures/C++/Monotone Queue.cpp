#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

#define MAX_SIZE 1000000

class monotone_queue{
    private:
        int min_arr[MAX_SIZE], fe, le;
        queue<int> q;
    public:
        void initialize(){
            fe = -1;
            le = 0;
        }

        int get_min(){
            return min_arr[fe];
        }

        void push(int x){
            q.push(x);
            int np;
            while(le!=fe){
                np = le-1;
                if (np<0)
                    np = MAX_SIZE-1;
                if (min_arr[np]>x)
                    le--;
                if (le<0)
                    le = MAX_SIZE-1;
            }
        }
};

int main(){
}

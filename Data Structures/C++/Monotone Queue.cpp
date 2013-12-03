#include <stdio.h>
#include <queue>
#include <deque>

using namespace std;

struct monotone_queue{
    queue<int> main_queue;
    deque<int> min_queue;

    void push(int x){
        main_queue.push(x);
        while(!min_queue.empty()&&x<min_queue.back()){
            min_queue.pop_back();
        }
        min_queue.push_back(x);
    }

    int pop(){
        int n = main_queue.front();
        if (n==min_queue.front()){
            min_queue.pop_front();
        }
        main_queue.pop();
        return n;
    }

    int get_min(){
        return min_queue.front();
    }

    int front(){
        return main_queue.front();
    }

    int size(){
        return main_queue.size();
    }
};

int main(){
    monotone_queue mq;
    //3,2,1,3,0,2
    mq.push(3);
    printf("Min: %d\n", mq.get_min());
    mq.push(2);
    printf("Min: %d\n", mq.get_min());
    mq.push(1);
    printf("Min: %d\n", mq.get_min());
    mq.pop();
    mq.push(3);
    printf("Min: %d\n", mq.get_min());
    mq.pop();
    mq.push(0);
    printf("Min: %d\n", mq.get_min());
    mq.pop();
    mq.pop();
    mq.pop();
    mq.push(2);
    printf("Min: %d\n", mq.get_min());
}

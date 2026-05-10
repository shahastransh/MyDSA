#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;

public:

void push(int data){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(data);

    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }

    return;

}

void pop(){
    s1.pop();

}

int front(){
    return s1.top();

}


bool empty(){
    return s1.empty();

}

void printQueue(){
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return;
}



};

int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    q.printQueue();


    return 0;
}
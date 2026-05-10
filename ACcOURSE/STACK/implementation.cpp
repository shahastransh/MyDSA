#include<iostream>
#include<vector>
using namespace std;

//create stack using vector
template<class T>

class Stack{
    vector<T> vec;
public:

    bool isEmpty(){
        return vec.size() == 0;
    }
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return;
        }
        vec.pop_back();
    }

    T top(){
        // if(isEmpty()){
        //     cout<<"Stack is empty "<<endl;
        //     return -1;
        // }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    
};

int main(){
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
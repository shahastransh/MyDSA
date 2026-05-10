#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
}

string reverse_string(string str){
    string ans;
    stack<char> s;
    for(int i = 0; i<str.size(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;

}

void reverse_stack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse_stack(s);
    pushAtBottom(s,temp);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;

}

int main(){
    stack<int> s;
    
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);

    reverse_stack(s);
    printStack(s);

    return 0;
}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isValid(string str){
    stack<char> s;

    for(int i = 0; i< str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }else{
            if(ch == ']' || ch == '}' || ch == ')'){
                if(s.empty()){
                    return false;
                }
                char top = s.top();
                if((ch == ')' && top == '(') 
                    || (ch == '}' && top == '{') 
                    || (ch == ']' && top == '[') ){
                        s.pop();
                }else{
                    return false;
                }
            }

            
        }

    }
    return s.empty();
}


int main(){
    string str1 = "([}])";
    string str2 = "([{}])";

    cout << isValid(str1) << endl << isValid( str2) << endl;

    return 0;
}
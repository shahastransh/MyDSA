#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_subset(string str, string subset){
    if(str.size() == 0){
        cout << subset << "\n";
        return;
    }

    char ch = str[0];
    print_subset(str.substr(1,str.size()-1), subset + ch);// yes
    print_subset(str.substr(1,str.size()-1), subset); // no
}

int main(){
    string str = "abc";
    string subset = "";
    print_subset(str, subset);

    return 0;
}
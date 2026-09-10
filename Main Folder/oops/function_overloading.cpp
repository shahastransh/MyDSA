#include<bits/stdc++.h>
using namespace std;

class Print{
    public:
    void display(int a){
        cout << "Integer: " << a << endl;
    }
    
    void display(string a){
        cout << "String: " << a << endl;
    }
};

int main(){
    Print p1;
    p1.display(42);
    p1.display("Hello, World!");
    return 0;
}
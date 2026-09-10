#include<bits/stdc++.h>
using namespace std;

class Parent{
    public:
    void display(){
        cout << "This is the parent class\n";
    }
};

class Child : public Parent{
    public:
    void display(){
        cout << "This is the child class\n";
    }
};

int main(){
    Child c1;
    c1.display(); // This will call the display method of the Child class

    return 0;
}
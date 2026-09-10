#include<bits/stdc++.h>
using namespace std;

class Parent{
    public:
    void display(){
        cout << "This is the parent class\n";
    }

    virtual void hello(){
        cout << "Hello from Parent class\n";
    }
};

class Child : public Parent{
    public:
    void display(){
        cout << "This is the child class\n";
    }

    void hello(){
        cout << "Hello from Child class\n";
    }
};

int main(){
    Child c1;
    c1.display(); // This will call the display method of the Child class

    Parent* p1;

    p1 = & c1;

    p1->hello(); // This will call the hello method of the Child class due to virtual function

    return 0;
}
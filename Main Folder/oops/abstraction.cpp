#include<bits/stdc++.h>
using namespace std;

class Shape{ //abstract class
    public:
    virtual void draw() = 0; // assign 0 to make a function pure virtual 
};


class Circle : public Shape{
    public:
    void draw(){
        cout << "Drawing Circle\n";
    }
};

class Square : public Shape{
    public:
    void draw(){
        cout << "Drawing Square\n";
    }
};

int main(){
    
    Circle c1;
    c1.draw();

    Square s1;
    s1.draw();

    return 0;
}
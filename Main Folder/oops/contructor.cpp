#include<bits/stdc++.h>
using namespace std;

class Car{
    string name;
    string color;

public:
    Car(){
        cout << "default constructor called\n";
    }
    Car(string name, string color){
        cout << "parameterized constructor called\n";
        this->name = name;
        this->color = color;
    }
    void start(){
        cout << "car has started..\n";
    }
    void stop(){
        cout << "car has stopped..\n";
    }

    string getName(){
        return name;
    }


};

int main(){
    Car c0;
    Car c1("BMW", "Black");
    cout << c1.getName() << endl;
    return 0;
}
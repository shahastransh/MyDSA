#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    string name;
    string color;

    Car(string name, string color){
        this->name = name;
        this->color = color;
    }

    //create your own copy constructor  aka custom copy constructor
    Car(Car &c){    
        cout << "copy constructor called\n";
        name = c.name;
        color = c.color;
    }


};

int main(){
    Car c1("BMW", "Black");
    
    Car c2(c1); // copy constructor called

    cout << c2.name << " " << c2.color << endl;

    return 0;
}
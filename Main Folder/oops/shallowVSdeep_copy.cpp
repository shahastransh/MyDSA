#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    string name;
    string color;
    int* mileage;

    Car(string name, string color){
        this->name = name;
        this->color = color;
        //dynamic allocation of memory for mileage
        mileage = new int; // allocate memory for mileage
        *mileage = 100; // initialize mileage
    }

    //create your own copy constructor  aka custom copy constructor
    //shallow copy constructor
    // Car(Car &c){    
    //     cout << "copy constructor called\n";
    //     name = c.name;
    //     color = c.color;
    //     mileage = c.mileage;
    // }

    Car(Car &c){    
        cout << "copy constructor called\n";
        name = c.name;
        color = c.color;
        mileage = new int; // allocate new memory for mileage
        *mileage = *c.mileage; // copy the value of mileage
        
    }


};

int main(){
    Car c1("BMW", "Black");
    
    Car c2(c1); // copy constructor called

    cout << c2.name << " " << c2.color << " " << *c2.mileage <<  endl;

    cout << " change in c2 mileage\n";
    *c2.mileage = 200; // change mileage of c2
    cout << "c2 mileage = " <<  *c2.mileage << endl;

    cout << *c1.mileage << endl;

    return 0;
}
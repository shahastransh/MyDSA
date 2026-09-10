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
    
    ~Car(){
        cout << "destructor called\n";
        if(mileage != NULL){
            delete mileage;
            mileage = NULL;
        }
    }
    


};

int main(){
    Car c1("BMW", "Black");
    
    
    cout << c1.name << " " << c1.color << " " << *c1.mileage <<  endl;

    
    return 0;
}
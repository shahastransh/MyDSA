#include<bits/stdc++.h>
using namespace std;

class Animal{
public:
    void eat(){
        cout << "eats\n";
    }

    void breathe(){
        cout << "breathes\n";
    }
};

class Mammal : public Animal{
public:
    string bloodType = "Warm";
};

class Dog : public Mammal{
public:
    void tailWag(){
        cout << "tail wagging\n";
    }
};

int main(){
    Dog d1;
    d1.eat();
    d1.breathe();
    cout << d1.bloodType << endl;
    d1.tailWag();
    return 0;
}
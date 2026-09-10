#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    string color;
    void eat(){
        cout << "Animal is eating\n";
    }
    void breathe(){
        cout << "Animal is breathing\n";
    }
};

class Fish : public Animal{//Access specifiers must bewrittenelsedefault=private
    public:
    int fins;
    void swim(){
        cout << "Fish is swimming\n";
    }
};

int main(){
    Fish f1;
    f1.color = "Blue";
    f1.fins = 4;
    cout << "Color: " << f1.color << endl;
    cout << "Fins: " << f1.fins << endl;
    f1.eat();
    f1.breathe();
    f1.swim();
    return 0;
}
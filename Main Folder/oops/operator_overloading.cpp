#include<bits/stdc++.h>
using namespace std;

class Complex{
    int real;
    int img;
public:
    Complex(int real,int img){
        this -> real = real;
        this -> img = img;
    }

    void display(){
        cout << real << "+" << img << "i" << endl;
    }

    Complex operator + (Complex &obj){
        int resReal = this -> real + obj.real;
        int resImg = this -> img + obj.img;
        Complex res(resReal,resImg);
        return res;
    }

};

int main(){
    Complex c1(3,4);
    c1.display();
    Complex c2(5,6);
    c2.display();

    Complex c3 = c1 + c2; // This will invoke the overloaded + operator
    c3.display();
    return 0;
}
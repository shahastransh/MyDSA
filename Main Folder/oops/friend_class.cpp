#include<bits/stdc++.h>
using namespace std;

class A{
    string secret = "This is a secret message";
    friend class B; // Declaring class B as a friend of class A
    friend void showSecret(A &a); // Declaring showSecret function as a friend of class A
};

class B{
    public:
    void revealSecret(A &a){
        cout << a.secret << endl; // Accessing private member of class A
    }
};

void showSecret(A &a){
    cout << a.secret << endl; // This function can also access private members of class A because it is a friend function
}

int main(){
    A a1;
    B b1;
    b1.revealSecret(a1); // B can access private members of A because it is a friend class
    return 0;
}
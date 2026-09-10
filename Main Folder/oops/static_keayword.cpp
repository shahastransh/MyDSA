#include<bits/stdc++.h>
using namespace std;

class Example{
    public:
    static int count; // Static member variable declaration
};

 int Example::count = 0; // Static member variable definition and initialization

int main(){
    Example e1, e2, e3;
    

    cout << e1.count++ << endl;
    cout << e2.count++ << endl;
    cout << e3.count++ << endl;

    cout << "Count: " << Example::count << endl; // Accessing static member variable using class name

    return 0;
}
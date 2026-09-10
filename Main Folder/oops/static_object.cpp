#include<bits/stdc++.h>
using namespace std;

class Example{
    public:
    Example(){
        cout << "Constructor called\n";
    }

    ~Example(){
        cout << "Destructor called\n";
    }
};


int main(){
    int a = 0;
    if(a == 0){
        static Example e1; // Constructor will be called here
    }
    
    
    cout << "End of main function\n";
    // Destructor will be called here when the program ends and e1 goes out of scope
    return 0;
}
#include <iostream>
using namespace std;


int main(){
    int a = 10;

    int* ptr = &a;
    int** parentPtr = &ptr;
    cout << &a<<endl<<ptr<<endl<<&ptr<<endl<<parentPtr<<endl;

    cout<<"new"<<endl;

    cout<< *(&a)<<endl<<*(ptr)<<endl<<*(*(parentPtr));



    return 0;
}
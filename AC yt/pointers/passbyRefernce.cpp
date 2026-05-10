#include <iostream>
using namespace std;

int changeA(int* ptr){
    *ptr = 20;
}
int changeB(int &b){
    b = 15;
}
int main(){
    
    int a = 10;
    int b = 5;
    int arr[]= {1,2,3,4,5};

    changeA(&a);
    changeB(b);
    cout << a << endl  << b << endl;
    cout << arr <<endl << *arr << endl;
    cout << "next element "<< *(arr+1)<<endl;
    cout << "next element "<< *(arr+2)<<endl;
    cout << "next element "<< *(arr+3)<<endl;
    cout << "next element "<< *(arr+4)<<endl;


    return 0;
}
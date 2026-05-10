#include <iostream>
using namespace std;


int main(){

    int size ;
    cout << "enter size of array";
    cin >> size;
    int marks[size];

    for(int i = 0; i < size; i++){
        cin >> marks[i];
    }
    

    int sz = sizeof(marks);
    cout << sz << endl;

    for(int i = 0; i < size; i++){
        cout << marks[i] <<" ";
    }


    return 0;
}
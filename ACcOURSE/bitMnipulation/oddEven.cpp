#include<iostream>
using namespace std;

void OddEven(int bin){
    if(bin & 1){
        cout << "odd";
    }else{
        cout << "even";
    }
}



int main(){

    OddEven(6);
    cout<<endl;
    
    OddEven(3);

    return 0;
}
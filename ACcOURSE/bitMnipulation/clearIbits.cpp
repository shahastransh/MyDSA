#include<iostream>
using namespace std;

int clearIbits(int num, int i){
    

    int bitMask = (~0 << i);
    num = num & bitMask;

    
    return num;

}


int main(){

    cout<< clearIbits(15,2);


    return 0;
}
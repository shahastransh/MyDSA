#include<iostream>
using namespace std;

int ithBit(int num, int i){
    int bitMask = 1<<i;

    return num | bitMask;
}


int main(){

    cout<< ithBit(6,3);


    return 0;
}
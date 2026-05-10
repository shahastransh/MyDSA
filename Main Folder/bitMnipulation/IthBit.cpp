#include<iostream>
using namespace std;

void ithBit(int num, int i){
    int bitMask = 1<<i;

    if(num & bitMask){
        cout << 1;
    }else{
        cout << 0;
    }
}


int main(){

    ithBit(6,0);


    return 0;
}
#include<iostream>
using namespace std;

int countSetBits(int num){
    

    int setBits = 0;
    while(num > 0){
        if(num & 1){
            setBits += 1;
        }

        num = num >> 1;
    }

    return setBits;

}


int main(){

    cout<< countSetBits(7);


    return 0;
}
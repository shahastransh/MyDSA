#include<iostream>
using namespace std;

int updateiTHBit(int num, int i, int val){
    

    int bitMask = ~(1 << i);
    num = num & bitMask;

    num = num | (val << i);
    return num;

}


int main(){

    cout<< updateiTHBit(7,3,1);


    return 0;
}
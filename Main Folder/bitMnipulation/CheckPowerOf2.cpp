#include<iostream>
using namespace std;

bool powerOf2(int num){
    

    if(num & (num-1)){
        return false;
    }else{
        return true;
    }

}


int main(){

    cout<< powerOf2(32);


    return 0;
}
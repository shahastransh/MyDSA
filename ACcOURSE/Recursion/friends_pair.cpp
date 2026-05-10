#include<iostream>
#include<string>
using namespace std;


int friends_pairing(int n){
    if(n == 1 || n == 2){
        return n;
    }
    return friends_pairing(n-1) + (n-1)*friends_pairing(n-2);
}


int main(){
    int n = 4;
    cout << friends_pairing(n);


    return 0;
}
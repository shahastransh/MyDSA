#include<iostream>
using namespace std;


int decToBin(int dec){
    int n = dec;
    int pow = 1;
    int bin = 0;

    while(n > 0 ){

        int rem = n % 2;
        bin += rem * pow;
        n = n/2;
        pow = pow * 10; 
        
    }
    return bin;

}


int main(){

    cout << "eNTER a Number ";

    int  n ;
    cin >> n;
    cout << " binary form is " << decToBin(n);

    return 0;
}
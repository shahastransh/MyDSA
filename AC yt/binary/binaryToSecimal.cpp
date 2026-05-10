#include <iostream>
using namespace std;

int binaryToDecimal(int binNum){
    int ans = 0 , pow = 1;

    while(binNum > 0){
        int rem = binNum % 10;
        binNum /= 10;
        ans += (rem * pow);
        pow *= 2; 

    }
    return ans;

}


int main(){
    int n;
    cout << "enter a number ";
    cin >> n;

    cout << binaryToDecimal(n);
    
    return 0;

}
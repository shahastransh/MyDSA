#include<iostream>
#include<string>
using namespace std;


void binary_string(int n, int last_place, string ans){
    if( n == 0){
        cout << ans << " ";
        return;
    }
    if(last_place != 1){
        binary_string(n-1,1,ans+'0');
        binary_string(n-1, 1 , ans + '1');

    }else{
        binary_string(n-1, 0, ans + '0');
    }
}

int main(){
    binary_string(3,0,"");

    return 0;
}
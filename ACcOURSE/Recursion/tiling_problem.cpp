#include<iostream>
using namespace std;

int tiling_problem(int n){
    if( n == 0 || n == 1){
        return 1;
    }

    // vertical
    int ans1 = tiling_problem(n-1);

    // horizontal
    int ans2 = tiling_problem(n-2);

    return ans1 + ans2;
}


int main(){
    int n = 5;
    cout << tiling_problem(n);

    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cnt = 0;
void print(){
    if (cnt == 3)
    return ;


    
    cout << cnt << endl;

    cnt = cnt+1;
    print();
    

}

int main(){

    print();

    return 0;

}
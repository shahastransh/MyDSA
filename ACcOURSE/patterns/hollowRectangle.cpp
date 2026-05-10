#include<iostream>
using namespace std;

int main(){
    int l;
    cout << "enter the length of rectangle: ";
    cin >> l;
    int b;  
    cout << "enter the breadth of rectangle: ";
    cin >> b;
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= b; j++){
            if(i == 1 || i == l || j == 1 || j == b){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}
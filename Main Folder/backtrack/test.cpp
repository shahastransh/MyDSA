#include<iostream>
using namespace std;

void print_arr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void change_arr(int arr[], int n, int i){
    if(i == n){
        print_arr(arr,n);
        return;
    }
    arr[i] = i+1;
    change_arr(arr, n, i+1);
    arr[i] -= 2; //backtrack


}

int main(){
    int arr[5] = {0};
    int n = 5;
    change_arr(arr, n, 0);
    print_arr(arr, n) ;

    return 0;
}
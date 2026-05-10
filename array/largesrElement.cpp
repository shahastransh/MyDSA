#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int largestElement(vector<int> &arr, int n){
    int largest = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];

        }
    }
    cout << largest;

}

int main(){
    int n;
    cin>>n;
   
    vector<int> v;
    for( int i =0; i<n; i++){
        cin >> n;
        v.push_back(n);
    }
    
    largestElement(v,n);

    return 0;
    
}
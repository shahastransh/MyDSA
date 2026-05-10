#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int secondLargest(vector<int> &a, int n){
    int largest = a[0];
    int slargest = -1;
    for(int i = 1; i<n; i++){
        if(a[i] > largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i]< largest && a[i] > slargest){
            slargest = a[i];
        }
    }
    return slargest;
    cout << slargest;
}

int secondSmallest(vector<int> &a, int n){
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i =1; i<n; i++){
        if(a[i]< smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < ssmallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;
    cout << ssmallest;
}
vector<int> getSecondOrderElemnt(int n, vector<int> a){
    int slargest = secondLargest(a,n);
    int ssmallest = secondSmallest(a,n);
    return{slargest,ssmallest}; 
}


int main(){
    int n;
    cin>>n;
   
    vector<int> v;
    for( int i =0; i<n; i++){
        cin >> n;
        v.push_back(n);
    }
    
    getSecondOrderElemnt(n,v);
    secondSmallest(v,n);
    secondLargest(v,n);
    

    return 0;
    
}
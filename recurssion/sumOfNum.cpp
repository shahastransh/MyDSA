#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sum(int n){
    if( n==0)
    return 0;
    return n + sum(n-1);
}


int main(){

    int n;
    cout<<"enter a number "<<"= ";
    cin>>n;
    cout<<sum(n);

    return 0;
}
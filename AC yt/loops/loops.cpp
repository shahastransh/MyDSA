#include<iostream>
using namespace std;

int main(){
    
    int n;
     bool isPrime =true;

    cout<<"enter a number";
    cin>>n;

    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            isPrime=false;
            break;
        }   
    }

    if(isPrime == true){
        cout<<"Prime number";
    }
    else{
        cout<<"non prime";
        }

        return 0;
    }
    

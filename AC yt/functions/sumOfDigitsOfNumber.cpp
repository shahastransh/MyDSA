#include<iostream>
using namespace std;

int num;
int digitSum=0;
int lastDigit;
int sum(int num){
    while(num>0){
        lastDigit = num%10;
        num=num/10;
        digitSum += lastDigit; 

    }
    cout<<digitSum;

}



int main(){
    int n;
    cout<<"enter a number ";
    cin >> n;
    sum(n);

    return 0;
}
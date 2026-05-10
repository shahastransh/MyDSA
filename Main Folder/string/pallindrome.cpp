#include<iostream>
#include<string.h>
using namespace std;

bool isPallindrome(char arr[], int n){
    int st = 0, end = n - 1;
    while(st < end){
        if(arr[st++] != arr[end--]){
            cout << "not a valid pallindrome\n";
            return false;
        }

        cout << "pallindrome\n";
        return true;
    }
}

int main(){
    char word[] = "racecar";
    isPallindrome(word,strlen(word));

    return 0;
}
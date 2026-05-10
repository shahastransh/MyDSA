#include<iostream>
#include<string.h>
using namespace std;

void reverse_char_array(char arr[], int n ){
    int st = 0, end = n-1;
    while(st < end){
        swap(arr[st], arr[end]);
        st++; end--;
    }
    cout << arr;
}

int main(){
    char word[] = "code";

    reverse_char_array(word, strlen(word));
    return 0;
}
#include <iostream>
#include <climits>
using namespace std;




void reverse(int arr[],int sz){
    int start = 0; int end = sz-1;

    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}



int main(){

    int size ;
    cout << "enter size of array";
    cin >> size;
    int nums[size];
    

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }
    
    reverse(nums,size);

    for(int i = 0; i<size;i++){
        cout<<nums[i]<<" ";
    }

    cout<<endl;

    


    return 0;
}
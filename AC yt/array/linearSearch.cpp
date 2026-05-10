#include <iostream>
#include <climits>
using namespace std;

int target;


int linearSearch(int arr[], int size){
    for(int i = 0; i<size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}


int main(){

    int size ;
    cout << "enter size of array";
    cin >> size;
    int nums[size];
    
    

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }

    cout << "enter target ";
    cin >> target;

    int s = linearSearch(nums,size);

    cout<<s;
    

    

        
    return 0;
}
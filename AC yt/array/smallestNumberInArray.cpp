#include <iostream>
#include <climits>
using namespace std;


int main(){

    int size ;
    cout << "enter size of array";
    cin >> size;
    int nums[size];
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int indexOfSmallest;
    int indexOfLargest ;

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }
    

    

    for(int i = 0; i < size; i++){
        if(nums[i]<smallest){
            smallest = nums[i];
            indexOfSmallest = i;
        }        
    }

    for(int i = 0; i < size; i++){
        if(nums[i]>largest){
            largest = nums[i];
            indexOfLargest = i;
            
        }        
    }

    cout << smallest << endl;
    cout << largest << endl;

    cout << "index of smallest" << indexOfSmallest << endl;
    cout << "index of largest" << indexOfLargest << endl;


    return 0;
}
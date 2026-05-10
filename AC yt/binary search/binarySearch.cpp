#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> vec, int target){
    int st = 0, end = (vec.size()-1);
    while(st <= end){
        int mid = st + (end -st)/2;
        if(target > vec[mid]){
            st = mid+1;
        }
        else if(target<vec[mid]){
            end = mid -1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> arr1 = {-1,0,3,4,5,9,12};
    int tar1 = 12;

    

    vector<int> arr2 = {-1,0,3,5,9,12};
    int tar2 = 0; 
    cout<<binarySearch(arr1,tar1)<<endl<<binarySearch(arr2,tar2);

    return 0;
}
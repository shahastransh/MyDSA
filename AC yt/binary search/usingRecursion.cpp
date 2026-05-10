#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> vec, int target, int st, int end){
   
   if(st <= end ){
    int mid = st + (end - st)/2;
    if(target>vec[mid]){
        return binarySearch(vec,target,mid+1,end);
    } 
    else if(target<vec[mid]){
        return binarySearch(vec,target,st,mid-1);
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
    cout<<binarySearch(arr1,tar1,arr1[0],arr1.size()-1)<<endl<<binarySearch(arr2,tar2,arr2[0],arr2.size()-1);

    return 0;
}
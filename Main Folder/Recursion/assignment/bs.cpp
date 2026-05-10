# include<bits/stdc++.h>
#include<vector>
using namespace std;

int bs(vector<int> vec, int st, int end, int key){
    if(st > end ){
        return -1;
    }
    int mid = st + (end - st)/2;

    if(vec[mid] == key){
        return mid;
    }

    else if(vec[mid] > key){
        return bs(vec, st, mid-1, key);
    }
    else{
        return bs(vec, mid + 1, end, key);
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    // sort(arr.begin(), arr.end());
    cout << bs(arr, 0, arr.size()-1, 5) ;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;



int search(int arr[], int si, int ei, int tarr){
    if(si > ei){
        return -1;
    }

    int mid = si + (ei - si)/2;
    if(arr[mid] == tarr){
        return mid;
    }

    if(arr[si] <= arr[mid]){
        if(arr[si] <= tarr && tarr <= arr[mid]){
            return search(arr, si, mid-1, tarr);
        }else{
            return search(arr, mid+1, ei, tarr);
        }
    }else{
        if(arr[mid] <= tarr && tarr <= arr[ei]){
            return search(arr, mid+1, ei, tarr);
        }else{
            return search(arr, si, mid-1, tarr);
        }
    }
}

int main(){
    int arr[7] = {4,5,6,7,0,1,2};
    int n = 7;
    int res = search(arr, 0, n-1, 2);
    cout << res;
    return 0;
}
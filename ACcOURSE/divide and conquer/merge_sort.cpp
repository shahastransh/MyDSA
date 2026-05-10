#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int si, int ei, int mid){
    vector<int> temp;
    int i = si, j = mid+1;
    while(i <= mid && j <= ei){
        if( arr[i] <=  arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    } 

    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);

    }

    //vector to arr
    for(int idx = si, x = 0; idx<=ei; idx++){
        arr[idx] = temp[x++];
    }
}

void merge_sort(int arr[], int si, int ei){
    int mid = si + (ei - si)/2;

    if(si >= ei){
        return;
    }

    merge_sort(arr,si, mid);
    merge_sort(arr, mid+1, ei);
    merge(arr, si, ei, mid);

}

void print_array(int arr[], int n){
    for( int i = 0; i<n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}


int main(){
    int arr[6] = {6,3,7,5,2,4};
    int n = 6;
    merge_sort(arr, 0, n-1);

    print_array(arr, 6);


    return 0;
}
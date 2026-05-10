#include<bits/stdc++.h>
using namespace std;


void print_array(int arr[], int n){
    for( int i = 0; i<n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int partition(int arr[], int si, int ei){
    int i = si - 1, pivot = arr[ei];
    for(int j = si; j < ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }

        
    }
    i++;
    swap(arr[i], arr[ei]);

    return i;
}

void quick_sort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }

    int pivotIdx = partition(arr,  si,  ei);

    quick_sort(arr, si, pivotIdx - 1);
    quick_sort(arr, pivotIdx + 1, ei);
}

int main(){
    int arr[6] = {6,3,7,5,2,4};
    int n = 6;

    quick_sort(arr, 0, n-1);
    print_array(arr,n);
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int i,vector<int> &arr, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxI = i;

    if(l < n && arr[l] > arr[maxI]){
        maxI = l;
    }
    if(r < n && arr[r] > arr[maxI]){
        maxI = r;
    }

    if(maxI != i){
        swap(arr[maxI], arr[i]);
        heapify(maxI,arr,n);
    }
    
}

void heap_sort( vector<int> &arr){
    int n = arr.size();
    //step 1 build max heap
    for(int i = n/2-1; i>=0; i--){
        heapify(i,arr,n);
    }
    //step 2 : puting elements to correct position
    for(int i = n-1; i>0;i--){
        swap(arr[0], arr[i]);
        heapify(0,arr,i);
    }

}

int main(){
    vector<int> arr = {1,4,2,5,3 };

    heap_sort(arr);

    for(int i : arr){
        cout << i << " " ;
    }

    return 0;
}
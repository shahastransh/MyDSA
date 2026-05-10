#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx = st-1, piv = arr[end];

    for(int j = st; j < end; j++){
        if(arr[j] <= piv){
            idx++;
            swap(arr[j], arr[idx]);

        }
    }

    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}



void quickSort(vector<int> &arr, int st, int end){
    if(st < end){
        int pivIdx = partition(arr,st,end);
        quickSort(arr,st,pivIdx-1); //left
        quickSort(arr,pivIdx+1,end);//right
    }

}




int main(){
    vector<int> arr = {5,2,6,4,3,1};

    quickSort(arr,0,arr.size()-1);

    for(int val : arr){
        cout << val << " ";
    }
    cout<<endl;


    return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int c, int minAllowedDist){
    int cows = 1 , lastPosition = arr[0];
    for(int i = 0; i<n; i++){
        
        if(arr[i] - lastPosition >= minAllowedDist){
            cows++;
            lastPosition = arr[i]; 
        }
        if(cows == c){
            return true;
        }
    }

    return false;
}



int allocateCow(vector<int>& arr, int N, int C){
    sort(arr.begin(),arr.end());
    int st = 1, end = arr[N-1] - arr[0]; int ans = -1;
    for(int i = 0; i <= arr.size()-1; i++){
        if(arr[i]>end){
            end = arr[i];
        }
        if(arr[i]<st){
            st = arr[i];
        }
    }
    while(st <= end){
        int mid = st +(end  - st)/2;

        if(isPossible(arr, N, C, mid)){
            ans =  mid;
            st = mid +1;
        }else{
            end = mid-1;
        }
    }


}


int main(){

    vector<int> arr={1,2,8,4,9};
    int N = 5, C = 3;
    
    cout << allocateCow(arr , N, C);

    return 0;
}
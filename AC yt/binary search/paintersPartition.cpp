#include <bits/stdc++.h>
using namespace std;
//O(log(sum)*n)
bool isPosible(vector<int>& arr, int n, int m, int maxAllowedTime){
    int painters =1 , time =0;
    for(int i = 0; i<n; i++){
        
        if(time + arr[i] <= maxAllowedTime){
            time += arr[i]; 
        }else{
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}



int minTimePaint(vector<int>& arr, int n, int m){
    int sum = 0, maxVal = INT_MIN;
    for(int i = 0; i<n ; i++){
        sum += arr[i];
        maxVal = max(maxVal,arr[i]);
    }


    int ans = -1;
    int st = maxVal , end = sum; // range of possible answers
    while( st <= end){
        int mid = st +(end  - st)/2;
        
        if(isPosible(arr,n,m,mid)){//left
            ans = mid;
            end = mid - 1;
        }else{//right
            st = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {40,30,20,10};
    int n = 4, m = 2;

    cout << minTimePaint(arr , n , m)<< endl;
    


    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;

int lis(vector<int> arr){
    unordered_set<int>s(arr.begin(), arr.end());
    
    vector<int>arr2(s.begin(), s.end());

    sort(arr2.begin(),arr2.end());

    int n = arr.size();
    int m = arr2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j< m+1; j++){
            if(arr[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;

            }else{
                dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int lis2(vector<int> arr, int n, int m, vector<vector<int>>&dp){
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(arr[n-1] == arr[m-1]){
        return dp[n][m] = lis2(arr, n-1, m-1, dp) + 1;
    }else{
        return dp[n][m] = max(lis2(arr, n-1, m, dp), lis2(arr, n, m-1, dp));
    }
}

int main(){
    vector<int> arr = {50,3,10,7,40,80};

    cout << lis(arr);
    return 0;
}
#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int mcm(vector<int> arr, int i , int j){
    if(i==j){
        return 0;
    }
    
    int ans =INT_MAX;
    for(int k = i; k < j; k++){
        int cost1 = mcm(arr,i,k);
        int cost2 = mcm(arr,k+1,j);
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans,currCost);
    }

    return ans;
}

int mcmMEM(vector<int> arr, vector<vector<int>> &dp, int i , int j){
    if(i==j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans =INT_MAX;
    for(int k = i; k < j; k++){
        int cost1 = mcmMEM(arr,dp,i,k);
        int cost2 = mcmMEM(arr,dp, k+1,j);
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans,currCost);
    }

    return dp[i][j] =  ans;
}

int mcmTAB(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    //initailize
    for(int i = 1; i < n; i++){
        dp[i][i] = 0;

    }

    for(int len = 2; len < n; len++){
        for(int i = 1; i <= n-len; i++){
            int j = i+len-1; //col of cell
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cout << dp[i][j] << " ";

        }
        cout << endl;
    }
    return dp[1][n-1];
}

int main(){
    vector<int> arr ={1,2,3,4,3};
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << mcm(arr,1,n-1)<<endl;

    cout << endl << mcmMEM(arr,dp,1,n-1) << endl;
    cout << endl << mcmTAB(arr) << endl;
    return 0;
}
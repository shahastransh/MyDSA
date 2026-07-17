#include<iostream>
#include<vector>
using namespace std;


int unbounded_Knapsack(vector<int> val, vector<int> wt, int W, int n){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i = 1 ; i < n+1; i++){
        for(int j = 1; j < W+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                dp[i][j] = max(itemVal + dp[i][j - itemWt], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }

    return dp[n][W];
}
int unbounded_Knapsack2(vector<vector<int>>&dp, vector<int> val, vector<int>wt,int W,int n){
    if(n == 0 || W == 0) return 0;

    int itemwt = wt[n-1];
    int itemVal = val[n-1];
    if(dp[n][W] != -1) return dp[n][W];
    if(itemwt <= W){
        int ans1 = itemVal + unbounded_Knapsack2(dp, val, wt, W- itemwt, n);
        int ans2 = unbounded_Knapsack2(dp, val, wt, W, n-1);
        return dp[n][W] = max(ans1,ans2);
    }else{
        return dp[n][W] = unbounded_Knapsack2(dp, val, wt, W, n-1);
    }
}


int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int W = 7;
    int n = 5;
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout << unbounded_Knapsack(val,wt,W,n) << "\n";
    cout << unbounded_Knapsack2(dp,val,wt,W,n) << "\n";
    return 0;
}
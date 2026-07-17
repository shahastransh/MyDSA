#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int> nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target + 1,0));

    for(int i = 1 ; i < n+1; i++){
        for(int j = 1; j < target + 1; j++){
            if(nums[i - 1] <= j){
                dp[i][j] = max(nums[i-1] + dp[i-1][ j - nums[i-1]], dp[i-1][ j]);
            }else{
                dp[i][j] = dp[i-1][ j];
            }
        }
    }

    for(int i = 1 ; i < n+1; i++){
        for(int j = 1; j < target + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } 

    return dp[n][target] == target;


}

bool targetSum2(vector<vector<int>>&dp, vector<int> nums, int target, int n){
    if(target == 0) return true;
    if(n == 0) return false;

    if(dp[n][target] != -1) return dp[n][target];

    if(nums[n-1] <= target){
        return dp[n][target] = targetSum2(dp, nums, target - nums[n-1], n-1) || targetSum2(dp, nums, target, n-1);
    }else{
        return dp[n][target] = targetSum2(dp, nums, target, n-1);
    }

}


int main(){
    vector<int> nums = {4,2,7,1,3};
    int target = 10;
    cout << targetSum(nums,target);
    vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
    cout << targetSum2(dp, nums, target, nums.size());
    return 0;
}
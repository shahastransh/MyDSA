#include<iostream>
#include<vector>
#include<string>
using namespace std;

int catlan(int n ){
    if(n == 1 || n == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 0; i <n; i++){
        ans += catlan(i) * catlan(n-i-1);
    }
    return ans;
}

int catlanMEM(int n ,vector<int> &dp){
    
    if(n == 1 || n == 0){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;
    for(int i = 0; i <n; i++){
        ans += catlanMEM(i,dp) * catlanMEM(n-i-1,dp);
    }
    return dp[n] = ans;
}

 int catlanTab(int n){
    vector<int> dp(n+1,0 );
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<n+1; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
 }

int main(){
    int n = 6;
    
    
    cout << catlan(n) << endl;
    vector<int> dp(n+1,-1 );

    cout << endl << catlanMEM(n,dp) << endl;
    cout << endl << catlanTab(n) << endl;
    return 0;
}
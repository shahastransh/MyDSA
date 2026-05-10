#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int majorityElement(vector<int>& nums) {
          int n = nums.size();


        // sort
        sort(nums.begin(), nums.end());

        // count frequency
        int freq = 1; int ans = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                freq++;
            }
            else{
                freq = 1; ans = nums[i];
            }
            if(freq > n/2){
                return ans;
            }
        }
        return ans; 
        
    }


    int main(){
    vector<int> nums = {1,1,1,1,2,2,2,2,4,4,4,4,9,9,9,9,9};
    int target = 13;
   

    int ans = majorityElement(nums);
    cout << ans;
    


    return 0;
}
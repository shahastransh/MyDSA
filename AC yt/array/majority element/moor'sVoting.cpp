#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int majorityElement(vector<int>& nums) {
          int freq = 0, ans = 0;

        for(int i = 0 ; i < nums.size(); i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }



        // int count = 0;
        // for(int val:nums){
        //     if(val == nums){
        //         count++;
        //     }
        // }
        // if(count > n/2) => ans;
        // else => -1




        return ans;
        
    }


    int main(){
    vector<int> nums = {1,1,1,1,2,2,2,2,4,4,4,4,9,9,9,9,9};
    int target = 13;
   

    int ans = majorityElement(nums);
    cout << ans;
    


    return 0;
}
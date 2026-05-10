#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> num, int target){
    vector<int> ans;
    int n = num.size();
    int i = 0 ; int j = n-1;
    while(i<j){
        int PS = num[i] + num[j];
        if(PS > target){
            j--;
        }
        else if(PS < target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    } 
    

}


int main(){
    vector<int> nums = {2,7,11,15};
    int target = 13;
   

    vector<int> ans = pairSum(nums, target);
    cout << ans[0] << ", " << ans[1];
    


    return 0;
}
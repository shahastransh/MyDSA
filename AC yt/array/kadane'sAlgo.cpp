#include <iostream>
#include<climits>
using namespace std;


int main(){
    int n =5;
    int arr[n] = {6,-28,5,8,9};
    int maxSum = INT_MIN;
    int currSum;
    for(int i = 0; i < n; i++ ){
        currSum += arr[i];
        
        maxSum = max(maxSum,currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }

    cout << "max subarray sum = " << maxSum <<endl;

    return 0;

}
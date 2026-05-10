#include <iostream>
#include<climits>
using namespace std;


int main(){
    int n =5;
    int arr[n] = {6,7,5,8,9};
    int maxSum = INT_MIN;

    for(int st=0; st < n; st++ ){
        int currSum = 0;
        for(int end=st; end < n; end++){
            currSum += arr[end];
            
            maxSum = max(currSum, maxSum);
        }
        
    }

    cout << "max subarray sum = " << maxSum <<endl;

    return 0;

}
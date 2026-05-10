#include<iostream>
#include<vector>
using namespace std;

int rec(int n){
    if( n == 0 || n == 1){
        return 1;
    }

    return rec(n-1) + rec(n-2);
}

int memoization(int n,vector<int> ways){
    
    if(n == 1 || n == 0){
        return 1;
    }

    if(ways[n] != -1){
        return ways[n];
    }

    ways[n] = memoization(n-1,ways) + memoization(n-2,ways);
    return ways[n]; 
    
}

int tabulation(int n){//allowed jumps ->1,2,3
    vector<int> ways(n+1,0);
    ways[0] = 1; 
    ways[1] = 1;
    ways[2] = 2;

    for(int i = 3; i<= n; i++){
        ways[i] = ways[i-1] + ways[i - 2] ;
    }

    return ways[n];
}

int main(){
    int n = 4;
    vector<int> ways(n+1,-1);

    cout << rec(n) << endl;

    cout << endl <<memoization(n,ways) << endl;

    cout << endl << tabulation(n) ;
    return 0;
}
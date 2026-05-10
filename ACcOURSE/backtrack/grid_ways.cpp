#include<iostream>
#include<string>
#include<vector>
using namespace std;


int grid_ways(int r, int c, int n, int m){
    if(r == n-1 && c == m-1){
        return 1;
    }
    if(c >= n){
        return 0;
    }
    if(r >= m){
        return 0;
    }

    int v1 = grid_ways(r, c+1, n, m);
    int v2 = grid_ways(r+1, c, n, m);
    return v1+v2; 
}

int main(){

    int n = 3;
    int m = 3;
    int ans = grid_ways(0,0,n,m);
    cout<<ans;
    return 0;
}
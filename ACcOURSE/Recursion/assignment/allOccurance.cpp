#include<bits/stdc++.h>
using namespace std;

void all_occ(vector<int> v, int key, int idx){
    if(idx == v.size()){
        return;
    }

    if(v[idx] == key){
        cout <<  idx << " " ;
    }
    all_occ(v, key, idx+1 );
}


int main(){
    vector<int> arr = {3,2,4,5,6,2,7,2,2};
    all_occ(arr, 2, 0);
    
    return 0;
}
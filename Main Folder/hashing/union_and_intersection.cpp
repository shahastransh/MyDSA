#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;

void getUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;
    for(int i = 0; i<arr1.size(); i++){
        s.insert(arr1[i]);
    }
    for(int i = 0; i<arr2.size(); i++){
        s.insert(arr2[i]);
    }

    for(auto ele : s){
        cout << ele << " ";
    }
}

void getIntersection(vector<int> arr1,vector<int> arr2){
    unordered_set<int> s;
    for(int i = 0; i<arr1.size(); i++){
        s.insert(arr1[i]);
    }

    for(int i = 0; i<arr2.size(); i++){
        if(s.count(arr2[i])){
            cout << arr2[i] << " ";
            s.erase(arr2[i]);
        }
    }
}

int main(){
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};
    getUnion(arr1,arr2);
    cout << endl;

    getIntersection(arr1,arr2);
    return 0;
}
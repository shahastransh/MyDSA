#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int getCeleb( vector<vector<int>> arr){
    stack<int> s;
    for(int i = 0; i<arr.size() ; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        if(arr[a][b] == 0){
            s.push(a);
        }else{
            s.push(b);
        }
    }

    int celeb = s.top();
    for(int i = 0; i<arr.size(); i++){
        if( ( i != celeb ) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
            return -1;
        }
        
    }
    return celeb;
}

int main(){
    vector<vector<int>> arr = {{0,1,0}, {0,0,0}, {0,1,0}};

    int ans = getCeleb(arr);

    cout<<"celeb is "<< ans;


    return 0;
}
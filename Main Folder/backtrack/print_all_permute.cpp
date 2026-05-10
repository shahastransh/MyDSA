#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permutation(string str, string ans){
    int n = str.size();
    if(n == 0){
        cout << ans << endl;
        return;
    }
    for(int i = 0; i<n; i++){
        char ch = str[i];
        string next_str = str.substr(0,i) + str.substr(i+1,n-i-1);
        permutation(next_str, ans + ch);
    }
}

int main(){
    string str = "abc";
    string ans = "";
    permutation(str,ans);

    return 0;
}
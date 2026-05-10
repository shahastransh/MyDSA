#include<iostream>
#include<string>
using namespace std;

void remove_duplicates(string str, string ans, int i, bool map[]){
    char ch = str[i];
    int mapIdx = (int)(ch - 'a');

    if(i == str.size()){
        cout << "ans : " << ans << endl;
        return;
    }

    if(map[mapIdx]){ // if true
        remove_duplicates(str, ans, i+1, map);
    }else{
        map[mapIdx] = true;
        remove_duplicates(str, ans+str[i], i+1, map);
    }

}

void remove_duplicates2(string str, string ans,  bool map[]){
    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(ch - 'a');
    str = str.substr(0,n-1);

    if( str.size() == 0){
        cout << "ans : " << ans << endl;
        return;
    }

    if(map[mapIdx]){ // if true
        remove_duplicates2(str,ans, map);
    }else{
        map[mapIdx] = true;
        remove_duplicates2(str, ch + ans,  map);
    }

}



int main(){
    string str = "shahastranshtiwari";
    string ans = "";
    bool map1[26] = {0};
    bool map2[26] = {0};

    remove_duplicates(str, ans, 0, map1);
    remove_duplicates2(str, ans,  map2);
    return 0;
}
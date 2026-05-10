#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;
    
    m["china"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["NEPAL"] = 10;
    
    
    for(pair<string,int> country : m){
        cout << country.first << ", " << country.second << endl;
    }

    if(m.count("Canada")){
        cout << "Canada exist ";
    }else{
        cout << "Canada does not exist ";
    }
    return 0;
}
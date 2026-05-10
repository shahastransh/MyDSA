#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(6);
    s.insert(8);

    s.erase(3);

    if(s.find(3) != s.end()){
        cout << "exist " << endl;
    }else{
        cout << "does not exist " << endl;
    }

    for(auto ele : s){
        cout << ele << endl;
    }

    return 0;
}
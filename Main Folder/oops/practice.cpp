#include<bits/stdc++.h>
using namespace std;

class User{
    int id;
    string password;
public:
    User(int id){
        this -> id = id;
    }
    string username;

    void setPassword(string s){
        password = s;
    }
    string getPassword(){
        return password;
    }
};

int main(){
    User u1(101);
    u1.username = "John Doe";
    u1.setPassword("12345");
    cout << u1.username << endl;
    cout << u1.getPassword() << endl;
    return 0;
}
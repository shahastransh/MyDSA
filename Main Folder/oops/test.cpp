#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    string name;
    float cgpa;

    void get_percerntage(){
        cout << 10 * cgpa << "%\n";
    }
};

int main(){
    Student s1;

    s1.cgpa = 9.8;
    s1.get_percerntage();

    return 0;
}
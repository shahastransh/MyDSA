#include<bits/stdc++.h>

using namespace std;

class Student{

    string name ;
    float cgpa;
public:
    void getPercentage(){
        cout << (cgpa * 10) << "%" << endl;
    }
    void setName(string n){
        name  = n;
    }
    void setCgpa(float c){
        cgpa = c;
    }

    string getName(){
        return name;
    }

    float getCgpa(){
        return cgpa;
    }
};

int main(){
    Student s1;
    s1.setName("John Doe");
    s1.setCgpa(8.5);

    cout << s1.getName() << endl;
    cout << s1.getCgpa() << endl;
    s1.getPercentage();

    cout << sizeof(s1) << endl;
}

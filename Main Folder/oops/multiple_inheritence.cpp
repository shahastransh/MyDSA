#include<bits/stdc++.h>
using namespace std;

class Teacher{
public:
    int salary;
    string subject;
};

class Student{
public:
    int cgpa;
    int rollNo;
};

class TA : public Teacher, public Student{
    public:
    string name;
};

int main(){
    TA ta1;
    ta1.name = "John Doe";
    ta1.salary = 50000;
    ta1.subject = "Mathematics";
    ta1.cgpa = 3.8;

    cout << "TA Name: " << ta1.name << endl;
    cout << "Salary: $" << ta1.salary << endl;
    cout << "Subject: " << ta1.subject << endl;
    cout << "CGPA: " << ta1.cgpa << endl;

    return 0;
}
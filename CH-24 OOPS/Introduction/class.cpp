#include<iostream>
using namespace std;

class Student{
//By default the class variables can only be accessed privately 
public:
    string name;
    int age, roll_num;
    string grade;
};

int main(){
    Student s1;
    s1.name = "Raj";
    s1.age = 25;
    s1.roll_num = 30;
    s1.grade = "A+";

    cout << s1.name << endl;
}
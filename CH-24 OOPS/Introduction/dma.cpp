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
    Student *s = new Student;
  //  *s.name = "Ronit";//expression must have class type but it has type "Student *"
    (*s).name = "Ronit";

    cout << s->name;
    

    return 0;
}
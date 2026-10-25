#include<iostream>
using namespace std;

class Student{
    string name;
    int age, rollNo;
    string grade;
    public:
    void setName(string s){
        if(s.size() == 0){
             cout << "Invalid name";
            return;
        }
        name = s;
    }
    void setGrade(string s){
        if(s.size() == 0){
             cout << "Invalid grade";
            return;
        }
        grade = s;
    }
    void setAge(int a){
        if(a <= 0){
            cout << "Invalid age";
            return;
        }
        age = a;
    }
    void setRollNo(int r){
        rollNo = r;
    }
    int getRollNo(){
        return rollNo;
    }
    string getName(){
        return name;
    }
    string getGrade(int pin){
        if(pin == 234){
            return grade; 
        }
        return " ";
    }
};

int main(){
    Student s1;
    
    s1.setRollNo(-2);
    s1.setName("");
    s1.setGrade("O");

    cout << endl << s1.getGrade(234) << endl;
   cout << s1.getRollNo()<< endl;
   cout << s1.getName();
}
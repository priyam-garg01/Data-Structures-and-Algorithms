#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:

    Person(string name, int age) : name(name), age(age) {}

   void introduce(){
        cout << "Hello my name is " << name << endl;
    }

};

class Employee : public Person{
    protected:
    string salary;

    public:
    Employee(string name, int age, string salary) : Person(name, age), salary(salary) {}

    void monthly_sal(){
        cout << "My monthly salary is " << salary << endl;
    }
};

class Manager : public Employee
{
    public:
    string department;
    
    Manager(string name, int age, string salary, string department): Employee(name, age, salary), department(department) {}

    void work(){
        cout << "I am managing the department " << department << endl;
    }
};
int main(){
    Manager A1("Rohan", 45, "200000", "Marketing");
    A1.introduce();
    
    return 0;
}
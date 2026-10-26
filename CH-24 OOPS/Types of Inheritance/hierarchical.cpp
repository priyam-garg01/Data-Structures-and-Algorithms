#include<iostream>
using namespace std;

class Human{
    protected:
    string name;
    int age;
    

    public:
        Human(){
            cout << "Hello Human" << endl;
        }

        Human(string name, int age){
            this->name = name;
            this->age = age;
        }
        ~Human(){
            cout << "Hello this is Human class destructor" << endl;
        }
        void work(){
            cout << "Working is on !" << endl;
        }

        void display(){
            cout << name << " " << age << endl;
        }

};

class Student: public Human{

    int rollNo, fee;

    public: 
    Student(string name, int age, int rollNo, int fee): Human(name, age)//Inline constructor
    {
        // this->name = name;
        // this->age = age;
        this->rollNo = rollNo;
        this->fee = fee;
    }

    Student(){
        cout << "Hello Student" << endl; 
    }
    ~Student(){
        cout << "This is Student class Destructor" << endl; 
    }
    void display(){
            cout << name << " " << age << " " << rollNo << " " << fee << endl;
        }
};

class Teacher : public Human{
    int salary;

    public:
    Teacher(int salary, string name, int age){
        this->salary = salary;
        this->name = name;
        this->age = age;
    }

    void display(){
        cout << name << " " << age << " " << salary << endl;
    }
};
int main(){
    Student A1("Rohit", 15, 45, 99);
    A1.display();//Firstly the call checks if display funct is present in self class and then checks for parent class

    Teacher T1(99000, "Ajay", 30);
    T1.display();

    return 0;
}
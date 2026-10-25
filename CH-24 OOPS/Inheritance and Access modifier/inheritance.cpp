#include<iostream>
using namespace std;

class Human {
    //By default private
    string name;

    protected:
    int wt;

    public:
    int age;
};

class Student : public Human{
    int fees;

    // protected:Stays as protected here
    // int wt;

    public: 
        int rollNum;
        
    // public: Stays as public here
    // int age;
};
class Student2 : protected Human{
    int fees;

    // protected:Stays as protected here
    // int wt;

    public: 
        int rollNum;
        
    // protected: Stays as protected here
    // int age;

    void fun(int a, int w){
        age = a;
        wt = w;
    }

    void display(){
        cout << age << " " << wt << " " << endl;
    }
};

int main(){
    Student A;
    // A.name = "Keshav";//'class Student' has no member named 'name'
    // A.fees = 233333;//'int Student::fees' is private within this context
    A.rollNum;

    Student2 B;
    B.fun(25, 56);
    B.display();


}
#include<iostream>
using namespace std;

class Human{

    public:
    string name;

    void display(){
        cout << "My name is " << name << endl;
    }
};

class Engineer : virtual public Human{
    public:
    string specialization;

    void work(){
        cout << "I have specialization in " << specialization << endl;
    }

};
class Youtuber : virtual public Human{
    public:
    int subs;

    void followers(){
        cout << "I have " << subs << " subscribers" << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber
{
    public: 
    int salary;

    CodeTeacher(){
        cout << "Hello coder\n";
    }

    CodeTeacher(string name, string specialization, int subs){
        this->name = name;
        this->specialization = specialization;
        this->subs = subs;
    }

    void display(){
        cout << "My name is " << name << endl;
        work();
        followers();
    }
};

int main(){
    CodeTeacher C1;
    C1.display();
     
    CodeTeacher C2;
    return 0;
}
#include<iostream>
using namespace std;
//Hierarchical + Multiple inheritance
class Student{
    string name;
    string rollNo;
    int age;

    public:
    void print(){
        cout << "Hello I am a student\n";
    }

};

class Male{
    string gender;
    public:
    void Maleprint(){
        cout << "Hello I am Male\n";
    }
};
class Female{
    string gender;
    public:
    void Femaleprint(){
        cout << "Hello I am Female\n";
    }
};

class Boy : public Male, public Student{
    public:
    void Boyprint(){
        cout << "Hello I am a boy\n";
    }
};

class Girl : public Student, public Female{


    public:

    void Girlprint(){
        cout << "Hello I am a girl\n";
    };
};
int main(){
        Girl G1;
        G1.Girlprint();
        Male M1;
        M1.Maleprint();

    return 0;
}
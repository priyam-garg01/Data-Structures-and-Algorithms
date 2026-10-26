#include<iostream>
using namespace std;

class Engineer{
    void money(){
        cout << "Hello money" << endl;
    }

    public:
    string specialization;

    Engineer(){
        cout << "Hello Engineer\n";
    }
    void work(){
        cout << "I have specialization in " << specialization << endl;
    }

};
class Youtuber{
    public:
    int subs;

    Youtuber(){
        cout << "Hello Youtuber\n";
    }

    void followers(){
        cout << "I have " << subs << " subscribers" << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber
{
    public: 
    string name;

    CodeTeacher(){
        cout << "Hello coder\n";
    }

    CodeTeacher(string name, string specialization, int subs){
        this->name = name;
        this->specialization = specialization;
        this->subs = subs;
    }

    void showcase(){
        cout << "My name is " << name << endl;
        work();
        followers();
    }
};

int main(){
    CodeTeacher C1("Roshan", "AI-DS", 5000);
    C1.showcase();
    // C1.money();Declared private cannot be accessed 
    CodeTeacher C2;
    return 0;
}
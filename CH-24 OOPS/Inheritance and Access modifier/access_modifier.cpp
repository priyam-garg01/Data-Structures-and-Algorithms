#include<iostream>
using namespace std;

class Human {
    private: int a;
    protected: int b;
    public: int c;
};

int main(){
    Human Rohit;
    // Rohit.a;//Cannot be used as declaration is private
    Rohit.c;
    // Rohit.b;//Cannot be used as declaration is protected
}

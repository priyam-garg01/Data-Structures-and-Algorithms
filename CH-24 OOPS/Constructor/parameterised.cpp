#include <iostream>
using namespace std;

class Customer{
    string name;
    int acc_num;
    int balance;

public: 
    //default constructor
    Customer(){
    
    }

    // //parameterised constructor
    // Customer(string name, int acc_num, int balance){
    //     this->name = name;
    //     this->acc_num = acc_num;
    //     this->balance = balance;
    // }

    //Inline constructor
    inline Customer(string a, int b, int c) : name(a), acc_num(b), balance(c){

    }

    //Copy Constructor(Default when not written)
    Customer(Customer &A){
        name = A.name;
        acc_num = A.acc_num;
        balance = A.balance;
    }

      void display(){
        cout << name << " " << acc_num << " " << balance <<"\n";
    }
};

int main()
{
    // Customer a1();
    Customer a1("Rohan", 34444, 579999);
    a1.display();
    Customer A2(a1);
    A2.display();
    Customer A3;
    A3 = A2;
    A3.display();

    return 0;
}
#include <iostream>
using namespace std;

class Customer{
    string name;
    int acc_num;
    int balance;
public:
//default constructor
    Customer(){
        cout << "Hello Construtor\n";
        name = "roh";
        acc_num = 344;
        balance = 999999999;
    }
    
    void display(){
        cout << name << " " << acc_num << " " << balance <<"\n";
    }
};
int main()
{
    // Customer a1();
    Customer a1;
    a1.display();

    return 0;
}
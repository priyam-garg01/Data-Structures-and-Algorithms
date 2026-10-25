#include <iostream>
using namespace std;

class Customer{
    string name;
    int *data;
public:
    
    Customer(){
        name = "4";
        cout << "Constructor is " << name << endl;
    }
    Customer(string name){
        this->name = name;
        cout << "Constructor is " << name << endl;
    }
    //Destructor
    ~Customer(){
        delete data;
        cout << "Destructor is " << name << endl;
    }
};
int main()
{
    // Customer a1();
    // Customer a1("3"), a2("%"), a3("T");
    // Customer *a4 = new Customer;
// Constructor is 3
// Constructor is %
// Constructor is T
// Constructor is 4
// Destructor is T
// Destructor is %
// Destructor is 3

    Customer a1("3"), a2("%"), a3("T");
    Customer *a4 = new Customer;
    delete a4;
// Constructor is 3
// Constructor is %
// Constructor is T
// Constructor is 4
// Destructor is 4
// Destructor is T
// Destructor is %
// Destructor is 3


    return 0;
}
#include<iostream>
using namespace std;

class Customer{

    string name;
    int acc_num, balance;
    static int tot_bal;
    static int tot_cust;//there will be a shared variable called tot_cust somewhere.
    public:

    Customer(string name, int acc_num, int bal){
        this->name = name;
        this->acc_num = acc_num;
        balance = bal;
        tot_cust++;
        tot_bal += bal;
    }
    static void accStatic(){//Can only access static data members
        cout << tot_cust << endl;
        cout << tot_bal << endl;

    }
    void deposit(int amount){
        if(amount > 0){
            balance += amount;
            tot_bal += amount;
        }
    }
    void withdrawl(int amount){
        if(amount <= balance){
            balance -= amount;
            tot_bal -= amount;
        }
    }

    void display(){
        cout << name << " " << acc_num << " " << tot_cust << endl;
    }
};

int Customer::tot_cust = 0;/*This is called the Scope Resolution Operator. It tells the compiler, 
"This tot_cust variable belongs to the Customer class."
This outside line is what actually creates the physical space in memory for it.*/
int Customer::tot_bal = 0;

int main(){

    Customer A1("Mohan", 233, 20000);
    Customer A2("Rohan", 253, 10000);
    Customer A3("Mohan", 283, 50000);
    Customer::accStatic();//when declared private we can define a static member function
    A1.deposit(45000);
    Customer::accStatic();//when declared private we can define a static member function
    A2.withdrawl(5000);
    Customer::accStatic();//when declared private we can define a static member function

    // Customer:: tot_cust = 67;//Can be changed only when the declaration is made public
    // A3.display();

    return 0;
}
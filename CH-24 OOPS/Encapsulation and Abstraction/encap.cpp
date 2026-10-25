#include<iostream>
using namespace std;

class Customer{
    string name;
    int bal, age;
    public:
    void setAge(int age){
        if(age > 0 && age <= 100){
            this->age = age;
        }
        else{
            cout<< "Invalid age !"<< endl;
        }
    }
    int getAge(){
            if(age > 0 && age <= 100)return age;
            return -1;
        }
    };




int main(){
    Customer A1;
    A1.setAge(456);
    cout << A1.getAge() << endl;;


    return 0;
}
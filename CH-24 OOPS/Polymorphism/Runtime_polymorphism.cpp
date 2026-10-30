#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class Animal{

    public:
    virtual void speak(){
        cout << "Hu Hu" << endl;
    }
    // void speak(){
    //     cout << "Hu Hu" << endl;
    // }
};

class Dog : public Animal{

    public:
    void speak(){
        cout << "Bark" << endl;
    }

};
class Cat : public Animal{

    public:
    void speak(){
        cout << "Meowww" << endl;
    }

};

int main(){
    Animal *p;
    p = new Dog();//New keyword allocates memory in heap during the runtime not compile time
    p->speak();//At compile time speak() function from the class to which p is pointing is stored in stack
    
    Dog *d;
    // d = new Animal();//a value of type "Animal *" cannot be assigned to an entity of type "Dog *"
/*parent can store the address of child class but not vice versa*/

//Use of virtual keyword
    vector<Animal*> vec;
    vec.push_back(new Dog());
    vec.push_back(new Cat());
    vec.push_back(new Animal());
    vec.push_back(new Dog());
    vec.push_back(new Cat());

    //To print the voices of all the stored animal classes addresses we check if it is of type dog, cat etc and then use their speak function
    // for(int i = 0; i < vec.size(); i++){
    //     if(typeid(*vec[i]) == typeid(Dog)){
    //         static_cast<Dog*>(vec[i])->speak();
    //     }
    //     else if{

    //     }
    //     else{

    //     }
    // }
    for(int i = 0; i < vec.size(); i++){
        vec[i]->speak();
    }

    return 0;
}
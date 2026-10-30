#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class Animal{

    public:
    virtual void speak() = 0;//Pure virtual or abstract function
        
    
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
    p = new Dog();
    p->speak();
    
//Use of virtual keyword
    vector<Animal*> vec;
    vec.push_back(new Dog());
    vec.push_back(new Cat());
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
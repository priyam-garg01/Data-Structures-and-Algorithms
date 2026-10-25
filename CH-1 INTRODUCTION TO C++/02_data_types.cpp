#include <iostream>

int main(){

    int age = 25;
    char grade = 'A';
    //ASCII values A-Z(65-90), a-z(97-122)

    float PI = 3.14f; 
    //'f' to represent float otherwise it assumes double data type
 
    bool isSafe = true;
    // true -> 1 & false -> 0

    bool notSafe = false; 

    float price = 100.99 ;
    //By default it is double

    std::cout << age <<"\n"<<PI<<"\n"<<isSafe<<"\n"<<notSafe<<"\n"<<price;
    


    return 0;
}

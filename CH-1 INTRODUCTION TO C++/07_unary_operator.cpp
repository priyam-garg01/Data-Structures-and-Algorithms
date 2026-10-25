#include<iostream>
using namespace std;

int main(){
    float a = 89.34, b = 78.123;
    int c = --a;
// a++ prints value of a and then increase it by '1'
// ++a increases it by '1' and then prints value of a 
    cout << c << endl;
    cout << a++ << endl;
    cout << a++ << endl;
    cout << ++a << endl;
    cout << ++b << endl;

    cout << --a << endl;


    return 0;
}
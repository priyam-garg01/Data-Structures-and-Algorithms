#include<iostream>
using namespace std;

int main(){
    float a, b;
    int s;
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter\n1 for Addition\n2 for Subtraction\n3 for Multiplication\n4 for Division\n5 for Modulo: ";
    cin >> s;

    if (s == 1)
    cout << a + b << endl;

    else if (s == 2)
    cout << a - b << endl;

    else if (s == 3)
    cout << a * b << endl;

    else if (s == 4)
    cout << a / b << endl;

    else if (s == 5)
    cout << int(a) % int(b) << endl;

    else
    cout << "Invalid input";
    
    return 0;
}
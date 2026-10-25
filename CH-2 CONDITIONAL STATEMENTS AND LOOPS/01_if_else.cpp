#include<iostream>
using namespace std;

int main(){
// Check if a number is positive or not
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (n > 0)
        cout << n << " is a positive number" << endl;
    else
        cout << n << " is a not positive number" << endl;

// Check if a person is eligible to vote or not
    int age;
    cout << "Enter the age: ";
    cin >> age;

    if (age >= 18 ){
        cout << "Age: " << age << endl;
        cout << "Eligible to vote";
    }
    else
    {
        cout << "Age: " << age << endl;
        cout << "Not eligible to vote"<< endl;
    }

// Check if a number is odd or even
    int n1;
    cout << "Enter the number: ";
    cin >> n1;

    if (n1 % 2 == 0)
        cout << n1 << " is an even number" << endl;
    else
        cout << n1 << " is an odd number" << endl;

    return 0;
}
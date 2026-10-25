#include<iostream>
using namespace std;

int main(){
// Find lowercase or uppercase charac
    char c;
    cout << "Enter the character: ";
    cin >> c;
    if (int(c) >= 65 && int(c) <= 90)
        cout << c << " is an Uppercase character" << endl;

    else if (int(c) >= 97 && int(c) <= 122)
        cout << c << " is an Lowercase character" << endl;

    else
        cout << c << " is not an English alphabet" << endl;

    return 0;
}
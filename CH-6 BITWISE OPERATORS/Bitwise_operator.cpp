#include <iostream>
using namespace std;

int main()
{
    int a = 4, b = 2;
    cout << (a & b) << endl; 
    cout << (a ^ b) << endl; 
    cout << (6 | 9) << endl;
    cout << (6 >> 2) << endl;
    cout << (9 >> 2) << endl;
    cout << (10 << 2) << endl;


    cout << (10 >> 1) << endl;
    cout << (6 & 10) << endl;
    cout << (6 | 10) << endl;
    cout << (6 ^ 10) << endl;
    

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    // int x = 256*256*256*256;//2^32
    // cout << x;//integer overflow=
    cout << sizeof(int) << endl; //4
    cout << sizeof(short int) << endl; //2
    cout << sizeof(long int) << endl; //4
    cout << sizeof(long long int) << endl;//8
    // Same as 
    cout << sizeof(long long) << endl;


    cout << sizeof(long double) << endl;

    unsigned int x = -10;
    cout << x << endl; // some random value from 0->2^32
    signed int y = -10; // or simply int 
    cout << y << endl;
    return 0;
}
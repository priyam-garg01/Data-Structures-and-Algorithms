#include <iostream>
using namespace std;

int main()
{
    int a = 199;
    // int* ptr = &a;
    // int** ptr2 = &ptr;

    // cout <<  a << endl;
    // cout <<  *(&a)<< endl;
    // cout <<  *(ptr)<< endl;
    // cout <<  **(ptr2)<< endl;

    // cout << &a << endl;
    // cout << ptr << endl;
    // cout << *(ptr2) << endl;
    // cout << **(&ptr2)<< endl;

    int* ptr3;
    cout << ptr3 << endl;//Returns a garbage value

    // For specifying the emptiness of a pointer
    int* ptr4 = NULL;
    cout << ptr4 << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << arr << endl;//arr returns address of arr[0]
    cout << &arr[0] << endl;
    int c = 15;
    // arr = &c; // arr are contant pointers
    // Error: expression must be a modifiable lvalue
    // where lvalue is arr
    // if lvalue is changeable then value stored will be lost
// But for other data types this is not true
    int a = 78;
    int*ptr = &a;
    cout << ptr << endl;
    int b = 90;
    ptr = &b;
    cout << ptr << endl;

    return 0;
}
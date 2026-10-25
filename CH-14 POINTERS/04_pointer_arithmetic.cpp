#include <iostream>
using namespace std;

int main()
{
    int a = 45;
    int* ptr = &a;

    cout << ptr << endl;
    // 0x61ff08
    cout << ++ptr << endl;
    // 0x61ff0c where c denotes 12
    ptr++;
    cout << ptr << endl;
    // 0x61ff10 = 0x61ff0c(12) +4 

    int* ptr1;//100
    int* ptr2 = ptr1 + 2;//108
    cout << ptr2 - ptr1 << endl;//2
    return 0;
}
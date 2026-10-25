#include <iostream>
using namespace std;

int main()
{
    // Inverted Triangle
    // For n = 4
    // 1 1 1 1
    //   2 2 2
    //     3 3
    //       4

    // int n = 4;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " "<< " ";
    // Here space bhi char ki tarah hai thats why do baar space
    //     }

    //     for (int k = 0; k < n - i; k++)
    //     {
    //         cout << i + 1 << " ";
    //     }

    //     cout << endl;
    // }

    // // CHARACTER VERSION
    // int n = 4;
    // char ch = 'A';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " " << " ";
    //     }
    //     for (int k = 0; k < n - i; k++)
    //     {
    //         cout << ch << " ";
    //     }
    //     ch++;
    //     cout << endl;
    // }

    // Pyramid shape
    // for n = 4
    // 1 1 1 1
    //  2 2 2
    //   3 3
    //    4

    // int n = 4;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout <<  " ";
    //     }

    //     for (int k = 0; k < n - i; k++)
    //     {
    //         cout << i + 1 << " ";
    //     }

    //     cout << endl;
    // }

    // CHARACTER VERSION
    int n = 4;
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < n - i; k++)
        {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
    return 0;
}
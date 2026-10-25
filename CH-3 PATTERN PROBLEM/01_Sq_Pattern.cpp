#include <iostream>
using namespace std;

int main()
{
    // Print the pattern for n = 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4

    int n = 5;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << j + 1 << " ";
    //     }
    //     cout << endl;
    // }

    // // For similar star pattern
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // // For similar ABCD pattern
    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A';
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    // Square pattern  n = 3
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // //M-1(ME)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << i * n + (j + 1) << " ";
    //     }
    //     cout << "" << endl;
    // }
    // //M-2
    // int num = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << "" << endl;
    // }

    // Similar for
    // A B C
    // D E F
    // G H I
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << "" << endl;
    }
    return 0;
}
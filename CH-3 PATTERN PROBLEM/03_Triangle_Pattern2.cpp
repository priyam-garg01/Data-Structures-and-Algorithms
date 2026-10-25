#include <iostream>
using namespace std;

int main()
{
    // //Triangle pattern
    // // for n = 4
    // // 1
    // // 1 2
    // // 1 2 3
    // // 1 2 3 4

    // // M-1
    // int n = 8;
    // for(int i = 0; i < n; i++)
    // {
    //     int num = 0;
    //     for(int j = 0; j < i + 1; j++)
    //     {
    //         num++;
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // // M-2
    // int n = 8;
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < i+1; j++)
    //     {
    //         cout << j+1 << " ";
    //     }
    //     cout << endl;
    // }

    // // CHARACTER VERSION
    // int n = 8;
    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A';
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    // Reverse Triangle pattern
    // for n = 4
    // 1
    // 2 1
    // 3 2 1
    // 4 3 2 1

   
    // // M-1
    // int n = 4;
    // for(int i = 0; i < n; i++)
    // {
    // for(int j = 0; j < i + 1; j++)
    // {
    //     cout << i + 1 - j << " ";
    // }
    //     cout << endl;
    // // }

    // // M-2
    // int n = 4;
    // for(int i = 0; i < n; i++)
    // {
    // for(int j = i+1; j; j--)
    // {
    //     cout << j  << " ";
    // }
    //     cout << endl;
    // }

    // (**) CHARACTER VERSION
    int n = 4;
    char ch = 'A';
    for(int i = 0; i < n; i++)
    {
        char ch = 'A'+ i;
        for(int j = 0; j < i+1 ; j++)
        {
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
    return 0;
}
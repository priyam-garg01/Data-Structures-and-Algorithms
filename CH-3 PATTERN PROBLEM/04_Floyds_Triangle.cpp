#include <iostream>
using namespace std;

int main()
{
    // FLOYD'S TRIANGLE
    // Pattern for n = 4
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10

    // // M-1
    // int n = 9;
    // int num = 1;

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < i + 1; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }
    // // M-2
    // int n = 9;
    // int num = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j; j--)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }
    // CHARACTER VERSION
    int n = 4;
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    return 0;
}
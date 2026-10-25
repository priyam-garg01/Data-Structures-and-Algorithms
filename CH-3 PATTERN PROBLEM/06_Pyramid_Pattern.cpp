#include <iostream>
using namespace std;

int main()
{
    // PYRAMID PATTERN
    // // For n = 4
    // //       1
    // //     1 2 1
    // //   1 2 3 2 1
    // // 1 2 3 4 3 2 1

    // int n = 4;
    // for (int i = 0; i < n; i++)
    // {

        // for (int j = n - i - 1; j; j--) //For spaces
    //     {
    //         cout << " " << " ";
    //     }
    //     for (int k = 0; k < i + 1; k++) //For front pattern
    //     {
    //         cout << k + 1 << " ";
    //     }
    //     for (int l = 0; l < i; l++) //For behind pattern
    //     {
    //         cout << l + 1 << " ";
    //     }
    //     cout << endl;
    // }

    // CHARACTER VERSION
    int n = 4;
    char ch, ch1;
    for (int i = 0; i < n; i++)
    { 
        ch = 'A';
        ch1 = 'A' + i-1;
        for (int j =0; j < n -i-1; j++)
        {
            cout << " " << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch << " ";
            ch++;
        }
        for (int j = 0; j < i; j++)
        {
            cout << ch1 << " ";
            ch1--;
        }
        cout << endl;
    }

    return 0;
}
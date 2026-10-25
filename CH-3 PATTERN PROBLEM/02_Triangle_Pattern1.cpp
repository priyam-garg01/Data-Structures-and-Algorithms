#include <iostream>
using namespace std;

int main()
{
// Right angled triangle for n = 4
// *
// * *
// * * *
// * * * *

    int n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << "" << endl;
    }


// // Similarly
// // 1
// // 2 2
// // 3 3 3
// // 4 4 4 4
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << i+1 << " ";
//         }
//         cout << endl;
//     }


// Similarly
// A
// B B
// C C C 
// D D D D
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }

    return 0;
}
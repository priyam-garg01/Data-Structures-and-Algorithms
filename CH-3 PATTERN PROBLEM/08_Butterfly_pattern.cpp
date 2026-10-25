#include <iostream>
using namespace std;

int main()
{
    // Butterfly Pattern
    // for n = 4
    // *             *
    // * *         * *
    // * * *     * * *
    // * * * * * * * *
    // * * * * * * * *
    // * * *     * * *
    // * *         * *
    // *             *

    int n = 16;
    // Top Part
    for (int i = 0; i < n; i++)
    {

        // Front stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        // Middle spaces
        for (int j = 0; j < 2 * (n - 1 - i); j++)
        {
            cout << " " << " ";
        }
        // Back stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    // Bottom part
    for (int i = 0; i < n; i++)
    {
        // Front stars(Simple triangle)
        for (int j = 0; j < (n - i); j++)
        {
            cout << "* ";
        }
        // Middle spaces
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " " << " ";
        }
        // Back stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }



    // // If this
    // // for n = 4
    // // *           *
    // // * *       * *
    // // * * *   * * *
    // // * * * * * * *
    // // * * * * * * *
    // // * * *   * * *
    // // * *       * *
    // // *           *
    // int n = 16;
    // // Top Part
    // for (int i = 0; i < n; i++)
    // {

    //     // Front stars
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     // Middle spaces
    //     for (int j = 0; j < 2 * (n - 1 - i) - 1; j++)
    //     {
    //         cout << " " << " ";
    //     }
    //     // Back stars
    //     if (i != n - 1)
    //     {
    //         for (int j = 0; j < i + 1; j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     else
    //     { //(n-1) stars in i = n
    //         for (int j = 1; j < n; j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     cout << endl;
    // }
    // // Bottom part
    // for (int i = 0; i < n; i++)
    // {
    //     // Front stars(Simple triangle)
    //     for (int j = 0; j < (n - i); j++)
    //     {
    //         cout << "* ";
    //     }
    //     // Middle spaces
    //     for (int j = 0; j < 2 * i - 1; j++)
    //     {
    //         cout << " " << " ";
    //     }

    //     // Back stars
    //     if (i != 0)
    //     {
    //         for (int j = 0; j < n - i; j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     else
    //     { // when i = 0 n-1 stars
    //         for (int j = 1; j < n; j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     cout << endl;
    // }

    return 0;
}
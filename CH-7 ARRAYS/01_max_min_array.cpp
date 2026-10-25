#include <iostream>
using namespace std;

int main()
{
    // For max
    int num[6] = {67488, -827272, 898, 28, 20, 0};
    int value = num[0];
    int index = 0;
    for (int i = 0; i < 6; i++)
    {
        if (num[i] > value)
        {
            value = num[i];
            index = i;
        }
        // instead of if we can use max function
        // value = max(num[i], value);
    }
    cout << "Max value in array is: " << value << endl;
    cout << index << endl;


    // // For min
    // int num[6] = {67488, -827272, 898, 28, 20, 0};
    // int value = num[0];
    // int index = 0;
    // for (int i = 0; i < 6; i++)
    // {
    //     if (num[i] < value)
    //     {
    //         value = num[i];
    //         index = i;
    //     }
    //     // instead of if we can use min function
    //     // value = min(num[i], value);
    // }
    // cout << "Min value in array is: " << value << endl;
    // cout << index;
    return 0;
}
#include <iostream>
using namespace std;
void revArray(int arr[], int size)
{
    int newArray[size];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[size - 1 - i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = newArray[i];
    }
}
int main()
{
    int arr[] = {4, 2, 7, 8, 1, 2, 5};

    // revArray(arr, 7);

//(*****) Usigng swap function(2 pointer approach)
    int start = 0, end = 7-1; //end = size -()
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++, end--;
    }

// // Using swap function
//     for (int i = 0; i < 6; i++)
//     {
//         swap(arr[i], arr[6 - i]);
//     }


    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

void bubbeSort(int arr[], int n)
{ // O(n^2)
    // better TC in sorting algo is nlogn

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Optimized approach for sorted arrays
// (T.C. toh same hi rahegi)
void bubbeSort(int arr[], int n)
{ // O(n^2)
    // better TC in sorting algo is nlogn

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        { // array is already sorted
            return;
        }
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    bubbeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
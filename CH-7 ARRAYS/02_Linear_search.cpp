#include <iostream>
using namespace std;

// Linear search algo
int linearSearch(int arr[], int size, int target){
    for (int i = 0; i < 7; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1; //Target value not found
}
int main()
{
    int arr[7] = {4, 2, 7, 8, 1, 55, 5};
    int target = 55;
    int index;
    for (int i = 0; i < 7; i++)
    {
        if (target == arr[i])
        {
            index = i;
            break;
        }
        else
            index = -1;
    }
    cout << index << endl;
    cout << linearSearch(arr, 7, 5);


    return 0;
}
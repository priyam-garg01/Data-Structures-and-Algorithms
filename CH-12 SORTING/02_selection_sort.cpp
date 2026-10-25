#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int smallestIdx = i;
            for(int j = i + 1; j < n; j++){
/* Comparing other index numbers that is why i + 1;*/     
            
                if(arr[j] < arr[smallestIdx]){
// To calculate min of all elements
                    smallestIdx = j;
                }
            }
            swap(arr[i], arr[smallestIdx]);
        }
    }


int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};


    selectionSort(arr, 5);

for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }


    return 0;
}
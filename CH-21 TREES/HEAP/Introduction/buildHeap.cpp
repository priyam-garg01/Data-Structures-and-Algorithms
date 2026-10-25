#include <iostream>
using namespace std;

void maxHeapify(int arr[], int index, int n){
    int l = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    
    while(left < n){
        l = index;
        if(left < n && arr[left] > arr[l])l = left;
        
        if(right < n && arr[right] > arr[l])l = right;

        if(l != index){
            swap(arr[l], arr[index]);
            index = l;
            left = 2*index + 1;
            right = 2*index + 2;
        }
        else break;
    }     
}

void buildMaxHeap(int arr[], int n){
    if(n == 0 || n == 1)return;

    for(int i = n/2 - 1; i >= 0; i--){
        maxHeapify(arr, i, n);
    }
}


void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr, n);

    display(arr, n);

    return 0;
}
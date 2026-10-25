#include <iostream>
#include <vector>
using namespace std;

int binarySearchR(vector<int> arr, int target, int st, int end){
    int n = arr.size();
    int mid;
    if(st <= end){
        mid = st + (end- st)/2;
        if(target < arr[mid]){//1st Half
            return binarySearchR(arr, target, st, mid-1);
        }
        else if(target > arr[mid]){//2nd Half
            return binarySearchR(arr, target, mid+1, end);
        }
        else    
            return mid;
    }
    return -1;
}
int binarySearch(vector<int> arr, int target){
    int n = arr.size();
    int st = 0, end = n-1, mid;
    while(st <= end){
        mid = st +(end - st)/2;
        if(target > arr[mid]){
            st = mid+1;
        }
        else if(target < arr[mid]){
            end = mid-1;
        }
        else
        return mid;
    }
    return -1;
}
int main()
{
    vector<int> arr1 = {2, 5, 6, 7, 8, 9};
    cout << binarySearchR(arr1, 45, 0, 5);
    return 0;
}
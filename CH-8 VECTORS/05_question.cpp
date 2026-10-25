#include <iostream>
#include <vector>
using namespace std;

// Linear search with vectors

int linearSearch(vector<int> &arr, int size, int target){
        for(int i = 0; i < size; i++){
            if(target == arr[i]){
                return i;
            }
        }
        return -1;
    }

// Reverse of vectors

void vecReverse(vector<int> &num, int size){
    vector<int> revNum(size);
    for(int i = 0; i < size; i++){
        revNum[i] = num[size-i-1];
    }
    
    for(int i = 0; i < size; i++){
        num[i] = revNum[i];
    }
    for(int i = 0; i < size; i++){
        cout << num[i] << endl;
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6,8};

    // cout << linearSearch(nums, 7, 8);

    vecReverse(nums, 7);
    // Originally nums bhi reverse hoga agar passed
    // by reference

   for(int i = 0; i < 7; i++){
        cout << nums[i] << endl;
    }
    
    return 0;
}
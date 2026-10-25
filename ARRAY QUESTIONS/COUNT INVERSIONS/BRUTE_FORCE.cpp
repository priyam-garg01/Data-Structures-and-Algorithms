/*
Given an integer array nums. Return the number of inversions in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
It indicates how close an array is to being sorted.
A sorted array has an inversion count of 0.
An array sorted in descending order has maximum inversion.


*/

class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {

int n = nums.size();
long long int count = 0;
    for(int i = 0; i <n; i++){
        for(int  j = i + 1; j < n; j++){
            if(nums[i] > nums[j]){
                count++;
            }
        }
    }
    return count;
    }
};
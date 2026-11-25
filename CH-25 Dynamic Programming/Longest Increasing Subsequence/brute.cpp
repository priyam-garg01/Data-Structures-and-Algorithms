/*Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int Lis(int i, int prevIdx, vector<int>& nums, int n){
        if(i == n)return 0;

        int notPick = Lis(i+1, prevIdx, nums, n);
        int pick = 0;
        if(prevIdx == -1 || nums[prevIdx] <nums[i])pick = 1 + Lis(i+1, i, nums, n);
        

        return max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prevIdx = -1;
        //Instead of storing the prev as val we store the prevIdx
        return Lis(0, prevIdx, nums, n);
    }
};/*Brute: Take if condition is met else dont take
T.C. = O(2^N), S.C. = O(N)*/

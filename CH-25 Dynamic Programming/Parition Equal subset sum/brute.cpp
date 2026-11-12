/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isPartition(int idx, int target, vector<int>& nums){
        if(target == 0)return true;
        if(idx == 0)return nums[idx] == target;

        bool pick = false;
        pick = isPartition(idx-1, target-nums[idx], nums);

        bool notPick = false;
        notPick = isPartition(idx-1, target, nums);

        return (pick | notPick);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        /*To find if the nums arr contains subsets with equal sum-> 
        Let the total arr sum be == S
        subsum1 == subsum2 == S/2;
        C-1 S == odd so S/2 is not a whole number so subsum1 can never equate to subsum2
        C-2 S == even so S/2 ==> whole number so our target is to find a sum of S/2 in the array 
        Problem similarizes to Subset sum with sum k
        */

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum%2 == 1)return false;
        return isPartition(n-1, sum/2, nums);
    }
};/*T.C. = O(2^N)+O(N), S.C. = O(N)*/
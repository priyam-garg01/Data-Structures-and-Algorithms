/*Given an array nums of n integers and an integer target, build an expression using the integers from nums where each integer can be prefixed with either a '+' or '-' sign.

The goal is to achieve the target sum by evaluating all possible combinations of these signs.

Determine the number of ways to achieve the target sum and return your answer with modulo 109+7.

Example 1:
Input: nums = [1, 2, 7, 1, 5], target = 4

Output: 2

Explanation: There are 2 ways to assign symbols to make the sum of nums be target 4.

+1 + 2 + 7 - 1 - 5 = 4

-1 + 2 + 7 + 1 - 5 = 4

Example 2:
Input: nums = [1], target = 1

Output: 1

Explanation: There is only one way to assign symbols to make the sum of nums be target 1.

Now Your Turn!
Pick the correct output for the given input
Input: nums = [2, 1, 3, 1, 2], target = 2

Constraints:
1 ≤ n ≤ 100
0 ≤ nums[i] ≤ 1000
0 <= sum(A[i]) <= 104
-1000 <= target <= 1000*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int mod = 1e9 + 7;

  int numComb(int idx, int target, vector<int>& nums){
    if(idx == 0){
        if(target == 0 && nums[idx] == 0)return 2;
        else if(target == 0 || target+nums[idx] == 0 || target-nums[idx] == 0)return 1;
        return 0;
    }
    // if(target == 0)return 1;//returns in between

    int Add = 0;
    int Diff = 0;

    Add = numComb(idx-1, target-nums[idx], nums);
    Diff = numComb(idx-1, target+nums[idx], nums);

    return (Add+Diff)%mod;
  }



  int targetSum(int n, int target, vector<int>& nums) {
    return numComb(n-1, target, nums);
 }
};//T.C. = O(2^N), S.C. = O(N)
/*Memoization Feasibility:Yes. But direct memoization on your (idx, target) approach is inefficient 
because target can be negative, making array indexing problematic.*/

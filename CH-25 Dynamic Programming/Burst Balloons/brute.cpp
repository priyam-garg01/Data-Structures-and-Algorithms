/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxiCoins(int i, int j, vector<int>& nums){
        if(i > j)return 0;

        int maxi = 0;
        for(int k = i; k <= j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1];
            coins += maxiCoins(i, k-1, nums) + maxiCoins(k+1, j, nums);
            maxi = max(maxi, coins);
        }

        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return maxiCoins(1, n, nums);
    }
};/*Brute Force: Think from the reverse side we take first partition k that we assume will be the last balloon to get burst
T.C. = Exponential*/
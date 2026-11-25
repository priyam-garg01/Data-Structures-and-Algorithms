#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            int maxLen = dp[i];
            for(int prev = 0; prev < i; prev++){
                int len = dp[i];
                if(nums[prev] < nums[i])len += dp[prev];
                maxLen = max(maxLen, len);
            }
            dp[i] = maxLen;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)ans = max(ans, dp[i]);

        return ans;
    }
};/*Tabulation Algorithm: Initialize all as 1 in the dp array, as min LIS will be 1 (itself). Move through 
the array and take prev till i-1 if the len of the current element can be incremented (nums>nums[prev]), store 
it in a max var, and at the end put the maximum len in dp. At last, find the max of all.
This sol cannot backtrack Lis*/
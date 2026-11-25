#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int Lis(int i, int prevIdx, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(i == n)return 0;
        if(prevIdx != -1 && dp[i][prevIdx+1] != -1)return dp[i][prevIdx+1];

        int notPick = Lis(i+1, prevIdx, nums, n, dp);
        int pick = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[i])pick = 1 + Lis(i+1, i, nums, n, dp);
        

        return dp[i][prevIdx+1] = max(pick, notPick);//Convert -1 to zero based
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prevIdx = -1;
        vector<int> dp(n+1, 0);
        vector<int> temp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            for(int prev = i-1; prev >= -1; prev--){//Prev is defined to be less than index i
                int notPick = dp[prev+1];
                int pick = 0;
                if(prev == -1 || nums[prev] < nums[i])pick = 1 + dp[i+1];

                temp[prev+1] = max(pick, notPick);//Convert -1 to zero based
            }
            dp = temp;
        }


        return dp[0];
    }
};/*SpaceOptimiz: S.C. = O(2N)*/
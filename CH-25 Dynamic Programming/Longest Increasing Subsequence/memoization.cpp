#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int Lis(int i, int prevIdx, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(i == n)return 0;
        if(prevIdx != -1 && dp[i][prevIdx+1] != -1)return dp[i][prevIdx+1];

        int notPick = Lis(i+1, prevIdx, nums, n, dp);
        int pick = 0;
        if(prevIdx == -1)pick = 1 + Lis(i+1, i, nums, n, dp);
        else if(nums[prevIdx] < nums[i])pick = 1 + Lis(i+1, i, nums, n, dp);
        

        return dp[i][prevIdx+1] = max(pick, notPick);//Convert -1 to zero based
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prevIdx = -1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //Instead of storing the prev as val we store the prevIdx
        return Lis(0, prevIdx, nums, n, dp);
    }
};/*Memoization: Adjusting initial -1 to dp
T..C = O(N*N), S.C. = O(N*N + N)*/
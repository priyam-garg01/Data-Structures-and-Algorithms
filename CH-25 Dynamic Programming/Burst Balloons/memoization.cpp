#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxiCoins(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int maxi = 0;
        for(int k = i; k <= j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1];
            coins += maxiCoins(i, k-1, nums, dp) + maxiCoins(k+1, j, nums, dp);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+1, -1));
        return maxiCoins(1, n, nums, dp);
    }
};/*Memoization: T.C. = O(N^3), S.C. = O(N^2 + N)*/
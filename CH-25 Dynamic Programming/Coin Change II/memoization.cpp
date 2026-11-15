#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int mod = 1e9+7;

        int numWaysCoins(int idx, int amount, vector<int>& nums, vector<vector<int>>& dp){
            if(idx == 0){
                if(amount%nums[idx] == 0)return 1;
                else return 0;
            }
            if(dp[idx][amount] != -1)return dp[idx][amount];
            int notTake = numWaysCoins(idx-1, amount, nums, dp);

            int take = 0;
            if(amount >= nums[idx])take = numWaysCoins(idx, amount-nums[idx], nums, dp);

            return dp[idx][amount] = (notTake+take)%mod;
        }

    int count(vector<int>&coins, int N, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return numWaysCoins(n-1, amount, coins, dp);
    }
};

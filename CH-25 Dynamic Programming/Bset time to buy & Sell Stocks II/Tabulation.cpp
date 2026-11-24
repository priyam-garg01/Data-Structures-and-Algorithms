#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        
        int allProfits(int i, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(i >= n)return 0;

        if(dp[i][buy] != -1)return dp[i][buy];
        //Buying
        if(buy == 0)return dp[i][buy] = max(allProfits(i+1, buy, prices, n, dp), allProfits(i+1, 1, prices, n, dp)-prices[i]);
        //Selling
        return dp[i][buy] = max(allProfits(i+1, buy, prices, n, dp), prices[i] + allProfits(i+1, 0, prices, n, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //We can buy and sell multiple times
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
      
        int buy = 0;
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                //Buying
                if(buy == 0)dp[i][buy] = max(dp[i+1][buy], dp[i+1][1]-prices[i]);

                //Selling
                else dp[i][buy] = max(dp[i+1][buy], prices[i] +dp[i+1][0]);
            }
        }
        return dp[0][0];
    }
};/*Tabulation: Starting from n as made from base case
T.C. = O(N*2), S.C. = O(N*2)*/
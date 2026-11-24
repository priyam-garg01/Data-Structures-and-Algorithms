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
        vector<vector<int>> dp(n, vector<int>(2, -1));
        //We also need to maintain dp state of buying

        return allProfits(0, 0, prices, n, dp);
    }
};/*Memoization: T.C. = O(N*2), S.C. = O(N)*/
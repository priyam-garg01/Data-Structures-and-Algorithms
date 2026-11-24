#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int profits(int i, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
        if(i == n || cap == 0)return 0;

        if(dp[i][buy][cap] != -1)return dp[i][buy][cap];
        int profit = 0;
        //Buying stock if buy = 1
        if(buy)
            profit = max(profits(i+1, buy, cap, prices, n, dp), profits(i+1, 0, cap, prices, n, dp)-prices[i]);//cap will be incremented only when a full transcation has occurred
        //Selling
        else
            profit = max(profits(i+1, buy, cap, prices, n, dp), prices[i] + profits(i+1, 1, cap-1, prices, n, dp));
        
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        //Dp will consist of idx, buy or not buy and cap remaining
        return profits(0, 1, 2, prices, n, dp);
    }
};/*Memoization:Requires cap as parameter too as we would not be able to see at what index with max profit has how many undone transactions
T.C. = O(N*2*3), S.C. = O(N*2*3 + N)*/
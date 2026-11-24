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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        //Dp will consist of idx, buy or not buy and cap remaining
        for(int i = 0; i <= n; i++){
            dp[i][0][0] = 0;
            dp[i][1][0] = 0;
        }
        for(int cap = 0; cap <=2; cap++){
            dp[n][0][cap] = 0;
            dp[n][1][cap] = 0;
        }

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;
                //Buying stock if buy = 1
                if(buy)
                    profit = max(dp[i+1][buy][cap], dp[i+1][0][cap] -prices[i]);//cap will be incremented only when a full transcation has occurred
                //Selling
                else
                    profit = max(dp[i+1][buy][cap], prices[i] + dp[i+1][1][cap-1]);
        
                dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};/*Tabulation
T.C. = O(N*2*3), S.C. = O(N*2*3)*/
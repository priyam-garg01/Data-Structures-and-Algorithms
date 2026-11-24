#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int profits(int i, int t, vector<int>& prices, int n, vector<vector<int>> dp, int k){
        if(i == n || t == 2*k)return 0;
        if(dp[i][t] != -1)return dp[i][t];
        
        int profit = 0;
        //Buying
        if(t%2 == 0)profit = max(profits(i+1, t, prices, n, dp, k), profits(i+1, t+1, prices, n, dp, k)-prices[i]);
        //Selling
        else profit = max(profits(i+1, t, prices, n, dp, k), profits(i+1, t+1, prices, n, dp, k)+prices[i]);

        return dp[i][t] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactions = 2*k;
        vector<vector<int>> dp(n, vector<int>(transactions+1, -1));

        return profits(0, 0, prices, n, dp, k); 
    }
};/*Memoization: T.C. = O(N*K*2), S.C. = O(N*K*2 + N)*/
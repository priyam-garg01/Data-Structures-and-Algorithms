#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactions = 2*k;
        vector<vector<int>> dp(n+1, vector<int>(transactions+1, 0));
        
        for(int i = n-1; i >= 0; i--){
            for(int t = 2*k-1; t >= 0; t--){
                int profit = 0;
                //Buying
                if(t%2 == 0)profit = max(dp[i+1][t], dp[i+1][t+1]-prices[i]);
                //Selling
                else profit = max(dp[i+1][t], dp[i+1][t+1]+prices[i]);

                dp[i][t] =  profit;
            }
        }

        return dp[0][0]; 
    }
};/*Tabulation: T.C. = O(N*K*2), S.C. = O(N*K*2)s*/
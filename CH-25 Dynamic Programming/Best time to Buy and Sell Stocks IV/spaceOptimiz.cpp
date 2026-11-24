#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactions = 2*k;
        vector<int> dp(transactions+1, 0);
        vector<int> temp(transactions+1, 0);
        
        for(int i = n-1; i >= 0; i--){
            for(int t = 2*k-1; t >= 0; t--){
                int profit = 0;
                //Buying
                if(t%2 == 0)profit = max(dp[t], dp[t+1]-prices[i]);
                //Selling
                else profit = max(dp[t], dp[t+1]+prices[i]);

                temp[t] =  profit;
            }
            dp = temp;
        }

        return dp[0]; 
    }
};/*SpaceOptimiz: S.C. = O(2K*2)*/
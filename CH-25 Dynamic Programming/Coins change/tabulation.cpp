#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        int target = amount;
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        //Base case:
        for(int i = 0; i < n; i++)dp[i][0] = 0;
        for(int t = 0; t <= target; t++){
            if(t%coins[0] == 0)dp[0][t] = t/coins[0];  
            else dp[0][t] = 1e9;      
        }

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){
                
                int notPick = dp[i-1][t];

                int pick = 1e9;
        
                if(t >= coins[i])pick = 1 + dp[i][t-coins[i]];

                dp[i][t] = min(pick, notPick);
            }
        }

        int ct = dp[n-1][target];
        if(ct == 1e9)return -1;
        return ct;
    }
};//T.C. = O(TARGET*N), S.C. = O(TARGET*N)
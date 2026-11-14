#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        int target = amount;
        vector<int> dp(target+1, 0);
        vector<int> temp(target+1, 0);
        //Base case:
        // for(int i = 0; i < n; i++)dp[i][0] = 0;
        for(int t = 0; t <= target; t++){
            if(t%coins[0] == 0)dp[t] = t/coins[0];  
            else dp[t] = 1e9;      
        }

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){
                
                int notPick = dp[t];

                int pick = 1e9;
        
                if(t >= coins[i])pick = 1 + temp[t-coins[i]];

                temp[t] = min(pick, notPick);
            }
            dp = temp;
        }

        int ct = dp[target];
        if(ct == 1e9)return -1;
        return ct;
    }
};//T.C. = O(N*TARGET), S.C. = O(2*TARGET)
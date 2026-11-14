#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int ctPossibleComb(int idx, vector<int>& coins,int target, vector<vector<int>>& dp){
        if(idx == 0){
            if(target%coins[0] == 0)return target/coins[0];
            return 1e9;
        }
        if(target == 0)return 0;

        if(dp[idx][target] != -1)return dp[idx][target];
        int notPick = ctPossibleComb(idx-1, coins, target, dp);

        int pick = 1e9;
        // if(target >= coins[idx])pick = target/coins[idx] + ctPossibleComb(idx-1, coins, target%coins[idx]);
        //If we take the max possible val from a coin it may be the case that the amount which could be filled if we had taken less denominations is not fullfilled now
        if(target >= coins[idx])pick = 1 + ctPossibleComb(idx, coins, target-coins[idx], dp);

        return dp[idx][target] = min(pick, notPick);
    }

	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        int target = amount;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int ct = ctPossibleComb(n-1, coins, target, dp);
        if(ct == 1e9)return -1;
        return ct;
    }
};//T.C. = O(N*TARGET), S.C. = O(TARGET*N) + O(TARGET) 
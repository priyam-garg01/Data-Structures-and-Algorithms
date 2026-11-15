#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        /*Type int triggers undefined behavior (signed overflow) during intermediate DP updates for large test cases.
        change DP type to unsigned int*/
        vector<unsigned int> dp(amount+1, 0);
        vector<unsigned int> temp(amount+1, 0);
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0)dp[i] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= amount; t++){
                unsigned int notTake = dp[t];

                unsigned int take = 0;
                if(t >= coins[i])take = temp[t-coins[i]];

                temp[t] = (notTake+take);
            }
            dp = temp;
        }

        return dp[amount];
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i = 1; i <= n; i++){
            dp[0][i] = price[0]*i;
        }

        for(int idx = 1; idx < n; idx++){
            for(int t = 0; t <= n; t++){
                int notCut = dp[idx-1][t];

                int Cut = 0;
                if(t >= idx+1)Cut = price[idx] +dp[idx][t-(idx+1)];

                dp[idx][t] = max(Cut, notCut);
            }
        }

        return dp[n-1][n];
    }
};
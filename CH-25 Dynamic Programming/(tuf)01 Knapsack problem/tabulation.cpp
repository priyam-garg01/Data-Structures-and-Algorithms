#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
            vector<vector<int>> dp(n, vector<int>(W+1, 0));
            // if(W >= wt[0])dp[0][wt[0]] = val[0];Incomplete base case
            //Base case should state that for evry wt >= wt[0] that lies at index 0 it return the val of item at index 0
            for(int w = wt[0]; w <= W; w++)dp[0][w] = val[0];

            for(int i = 1; i < n; i++){
                for(int w = 0; w <= W; w++){
                    int notPick = dp[i-1][w];

                    int pick = 0;
                    if(w >= wt[i])pick = val[i] + dp[i-1][w-wt[i]];

                    dp[i][w] = max(pick, notPick); 
                }
            }

            return dp[n-1][W];
        }
};//T.C. = O(N*W), S.C. = O(N*W)s
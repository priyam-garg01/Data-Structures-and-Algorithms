#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int maximizeSum(int idx, vector<int>& wt, vector<int>& val, int W, vector<vector<int>>& dp){
            if(idx == 0){
                if(W >= wt[0])return val[0];
                return 0;
            }
            if(W == 0)return 0;
            if(dp[idx][W] != -1)return dp[idx][W];

            int notPick = maximizeSum(idx-1, wt, val, W, dp);

            int pick = 0;
            if(W >= wt[idx])pick = val[idx] + maximizeSum(idx-1, wt, val, W-wt[idx], dp);

            return dp[idx][W] = max(pick, notPick); 
        }

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {

            vector<vector<int>> dp(n, vector<int>(W+1, -1));
            return maximizeSum(n-1, wt, val, W, dp);
        }
};//T.C. = O(N*W), S.C. = O(N*W + N)
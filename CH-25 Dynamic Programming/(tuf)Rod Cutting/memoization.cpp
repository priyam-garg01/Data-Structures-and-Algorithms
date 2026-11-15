#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int maxCutProfit(int idx, int N, vector<int>& price, vector<vector<int>>& dp){
        if(idx == 0){
            if(N == 0)return 0;
            if(N >= 1)return price[0]*N;
        }

        if(dp[idx][N] != -1)return dp[idx][N];
        int notCut = maxCutProfit(idx-1, N, price, dp);

        int Cut = 0;
        if(N >= idx+1)Cut = price[idx] + maxCutProfit(idx, N-(idx+1), price, dp);

        return dp[idx][N] = max(Cut, notCut);
    }
    
    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return maxCutProfit(n-1, n, price, dp);
    }
};
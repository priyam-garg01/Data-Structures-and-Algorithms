#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int findCost(int idx, vector<int>& height, vector<int>& dp){
        if(idx == 0)return 0;
        if(dp[idx] != -1)return dp[idx];
   
        int left = findCost(idx-1, height, dp) + abs(height[idx] - height[idx-1]);
        int right = 1e9;
        if(idx>1)right = findCost(idx-2, height, dp) + abs(height[idx] - height[idx-2]);
        

        return dp[idx] = min(left, right);
        
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        
        return findCost(n-1, height, dp);
    }//T.C. = 0(N), S.C. = 0(2N)
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        int idx = 1;
        
        while(idx <= n-1){
            int jump1 = dp[idx-1] + abs(height[idx]-height[idx-1]);
            int jump2 = 1e9;
            if(idx>1)jump2 = dp[idx-2] + abs(height[idx]-height[idx-2]);
            dp[idx] = min(jump1, jump2);
            idx++;
        }
        
        
        return dp[n-1];
    }//T.C. = O(N), S.C. = O(N)
};
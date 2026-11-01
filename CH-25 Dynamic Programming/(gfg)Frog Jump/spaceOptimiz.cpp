#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev = 0;
        int nextPrev = 0;
        int idx = 2;
        int ans;
        while(idx <= n-1){

            // int jump1 = dp[idx-1] + abs(height[idx]-height[idx-1]);
            int jump1 = prev + abs(height[idx]-height[idx-1]);
            int jump2 = 1e9;
            // if(idx>1)jump2 = dp[idx-2] + abs(height[idx]-height[idx-2]);
            jump2 = nextPrev + abs(height[idx]-height[idx-2]);
            
            // dp[idx] = min(jump1, jump2);
            ans = min(jump1, jump2);
            nextPrev = prev;
            prev = ans;
            idx++;
        }
        
        
        return prev;//as at the end the ans will move to n idx and our ans = dp[n-1]
    }//T.C. = O(N), S.C. = O(1)
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
  
    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        
        int idx = 2;
        while(idx <= n){
            dp[idx] = dp[idx-1] + dp[idx-2];
            idx++;
        }
        
        
        return dp[n];
    }//T.C. = O(N), S.C. = O(N)
};
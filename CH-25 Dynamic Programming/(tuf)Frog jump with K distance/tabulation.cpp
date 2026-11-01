#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int idx = 1;
            int mini = 1e9;
            while(i-idx >= 0 && idx<=k){
                int jump = abs(heights[i]-heights[i-idx])+dp[i-idx];
                mini = min(jump, mini);
                idx++;
            }
            dp[i] = mini;
        }
        return dp[n-1];
    }//T.C. = O(N*K), S.C. = O(N)
};
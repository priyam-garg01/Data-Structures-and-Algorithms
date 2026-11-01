#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEnergy(int idx, vector<int>& heights, int k, vector<int>& dp){
        if(idx == 0)return 0;
        if(dp[idx] != -1)return dp[idx];

        int mini = 1e9;
        int i = 1;
        while(i <= k && idx-i >= 0){
            int jump = abs(heights[idx] - heights[idx-i])+minEnergy(idx-i, heights, k, dp);
            mini = min(jump, mini);
            i++;
        }
        return dp[idx] = mini;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);

        return minEnergy(n-1, heights, k, dp);
    }//T.C. = O(N*K), S.C. = O(N + N)
};
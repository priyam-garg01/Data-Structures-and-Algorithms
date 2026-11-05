#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        for(int idx = 0; idx < n; idx++){
            int P = nums[idx];
            if(idx >= 2)P += dp[idx-2];
            int nP = 0;
            if(idx >= 1)nP = dp[idx-1];

            dp[idx] = max(P, nP);
        }
        
        return dp[n-1];
    }
};//T.C. = O(N), S.C. = 0(N)
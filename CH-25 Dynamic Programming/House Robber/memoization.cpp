#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int MaxSum(int idx, vector<int>& nums, vector<int>& dp){
        if(idx < 0)return 0;
        if(dp[idx] != -1)return dp[idx];

        int P = nums[idx] + MaxSum(idx-2, nums, dp);
        int nP = MaxSum(idx-1, nums, dp);

        return dp[idx] = max(P, nP);
    }

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return MaxSum(n-1, nums, dp);
    }
};//T.C. = O(N), S.C. = O(2N)
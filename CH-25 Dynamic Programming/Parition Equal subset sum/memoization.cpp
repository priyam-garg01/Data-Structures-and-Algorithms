#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isPartition(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0)return dp[idx][target] = true;
        if(idx == 0)return dp[idx][target] = nums[idx] == target;
        if(dp[idx][target] != -1)return dp[idx][target];

        bool pick = false;
        if(target >= nums[idx])pick = isPartition(idx-1, target-nums[idx], nums, dp);

        bool notPick = false;
        notPick = isPartition(idx-1, target, nums, dp);

        return dp[idx][target] = (pick || notPick);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        /*To find if the nums arr contains subsets with equal sum-> 
        Let the total arr sum be == S
        subsum1 == subsum2 == S/2;
        C-1 S == odd so S/2 is not a whole number so subsum1 can never equate to subsum2
        C-2 S == even so S/2 ==> whole number so our target is to find a sum of S/2 in the array 
        Problem similarizes to Subset sum with sum k
        */
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum%2 == 1)return false;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return isPartition(n-1, target, nums, dp);
    }
};/*T.C. = O(N*target) + O(N), S.C. = O(N*target) + O(N)*/
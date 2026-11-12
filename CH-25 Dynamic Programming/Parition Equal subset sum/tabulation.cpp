#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        //Base cases:
        for(int i= 0; i < n; i++){
            dp[i][0] = 1;
        }
        if(nums[0] == target){
            dp[0][nums[0]] = 1;
        }

        for(int idx = 1; idx < n; idx++){
            for(int t = 1; t <= target; t++){
                bool pick = false;
                if(t >= nums[idx])pick = dp[idx-1][t-nums[idx]];

                bool notPick = false;
                notPick = dp[idx-1][t];

                dp[idx][t] = pick || notPick;
            }
        }

        return dp[n-1][target];
    }
};/*T.C. = O(N*target) + O(N), S.C. = O(N*TARGET)s*/
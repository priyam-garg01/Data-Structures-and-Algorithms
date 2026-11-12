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
        vector<int> dp(target+1, 0);
        vector<int> temp(target+1, 0);

        //Base cases:
        dp[0] = 1;
        temp[0] = 1;

        if(nums[0] == target){
            dp[nums[0]] = 1;
        }

        for(int idx = 1; idx < n; idx++){
            for(int t = 1; t <= target; t++){
                bool pick = false;
                if(t >= nums[idx])pick = dp[t-nums[idx]];

                bool notPick = false;
                notPick = dp[t];

                temp[t] = pick || notPick;
            }
            dp = temp;
        }

        return dp[target];
    }
};/*T.C. = O(N*TARGET) + O(N), S.C. = O(2*TARGET)*/
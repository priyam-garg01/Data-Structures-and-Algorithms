#include<bits/stdc++.h>
using namespace std;
//Problem similarized to ct partitions with given diff
class Solution {
  public:
  int mod = 1e9 + 7;

  int numComb(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
    if(idx == 0){
        if(target == 0 && nums[idx] == 0)return 2;
        else if(target == 0 || target == nums[idx])return 1;
        return 0;
    }
    if(dp[idx][target] != -1)return dp[idx][target];
    // if(target == 0)return 1;//returns in between

    int notPick = numComb(idx-1, target, nums, dp);
    int Pick = 0;

    if(target >= nums[idx])Pick = numComb(idx-1, target-nums[idx], nums, dp);

    return dp[idx][target] = (notPick+Pick)%mod;
  }
//   int numComb(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
//     if(idx == 0){
//         if(target == 0 && nums[idx] == 0)return 2;
//         else if(target == 0 || target+nums[idx] == 0 || target-nums[idx] == 0)return 1;
//         return 0;
//     }
//     if(dp[idx][target] != -1)return dp[idx][target];
//     // if(target == 0)return 1;//returns in between

//     int Add = 0;
//     int Diff = 0;

//     Add = numComb(idx-1, target-nums[idx], nums, dp);
//     Diff = numComb(idx-1, target+nums[idx], nums, dp);

//     return dp[idx][target] = (Add+Diff)%mod;
//   }



  int targetSum(int n, int target, vector<int>& nums) {
    //subset sum with given diff s1-s2 = D(same case is here)
    //s1 = sum-s2 -> s2 = (sum-D)/2
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
    int t = (sum-target)/2;
    if((sum-target) < 0 || (sum-target)%2 != 0)return 0;
    //If sum-target is odd dividing it by 2 yields a fraction.No integer subset can sum to a non-integer value, making the target unreachable.
    vector<vector<int>> dp(n, vector<int>(t+1, -1));
    return numComb(n-1, t, nums, dp);
 }
};

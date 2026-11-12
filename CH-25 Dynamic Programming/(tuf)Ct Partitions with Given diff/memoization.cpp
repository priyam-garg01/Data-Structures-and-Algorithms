#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mod = 1e9+7;
    int ctPartition(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == 0){
            if(target == 0 && arr[0] == 0)return 2;
            else if(target == 0 || target == arr[0])return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1)return dp[idx][target];
        int notPick = ctPartition(idx-1, target, arr, dp);

        int pick = 0;
        if(target >= arr[idx])pick = ctPartition(idx-1, target-arr[idx], arr, dp);

        return dp[idx][target] = (pick + notPick)%mod; 
    }
    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        //we need s1 > s2 ; s1 = sum - s2 
        //also s1 - s2 = D => sum - 2*s2 = D => s2 = (sum-D)/2
        //Hence we need to find subsets that have sum = s2;
        int target = (sum-diff)/2;
        if((sum-diff)%2 != 0 || target < 0)return 0;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return ctPartition(n-1, target, arr, dp);
    }
};/*T.C. = O(N*TARGET), S.C. = O(N*TARGET) + O(NB)*/
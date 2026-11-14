#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mod = 1e9+7;
   
    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        //we need s1 > s2 ; s1 = sum - s2 
        //also s1 - s2 = D => sum - 2*s2 = D => s2 = (sum-D)/2
        //Hence we need to find subsets that have sum = s2;
        int target = (sum-diff)/2;
        if((sum-diff) < 0 || (sum-diff)%2 != 0)return 0;

        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        dp[0][0] = 1;
        if(arr[0] == 0)dp[0][0] = 2;
        if(target >= arr[0] && arr[0] != 0)dp[0][arr[0]] = 1;

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){
                int notPick = dp[i-1][t];

                int pick = 0;
                if(t >= arr[i])pick = dp[i-1][t-arr[i]];

                dp[i][t] = (pick + notPick)%mod; 
            }
        }
        return dp[n-1][target];
    }
};
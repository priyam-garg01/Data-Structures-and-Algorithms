#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:

    bool getTarget(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0)return dp[idx][target] = true;
        if(idx == 0)return dp[idx][target] = target == arr[0];
        if(dp[idx][target] != -1)return dp[idx][target];

        bool notPick = getTarget(idx-1, target, arr, dp);

        bool Pick = false;
        if(target >= arr[idx]) Pick = getTarget(idx-1, target-arr[idx], arr, dp);

        return Pick || notPick;
    }

	int minDifference(vector<int>&arr, int n)  { 
        int sum = 0; 
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        int target = 0;
        if(sum%2 == 0)target = sum/2;
        else target = sum/2+1;
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i = 0; i <= n-1; i++){
            dp[i][0] = 1;
        }
        if(sum >= arr[0])dp[0][arr[0]] = 1;

        for(int i = 1; i < n; i++){
            for(int t = 1; t <= sum; t++){
                bool notPick = dp[i-1][t];

                bool Pick = false;
                if(t >= arr[i]) Pick = dp[i-1][t-arr[i]];

                dp[i][t] = Pick || notPick;
            }
        }


        for(int t = target; t <= sum; t++){
            if(dp[n-1][t] == 1)return t-(sum-t);
        }

	} 
};//T.C. = O(N*SUM) + O(Sum/2), S.C. = O(N*Sum);
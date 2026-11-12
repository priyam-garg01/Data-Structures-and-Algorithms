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
       
        int target = 0;//The min diff can be zero; iterating from target to sum if there is a true val returned we return the diff
        if(sum%2 == 0)target = sum/2;
        else target = sum/2+1;
        
        for(int t = target; t <= sum; t++){
            vector<vector<int>> dp(n, vector<int>(t+1, -1));
            bool val =  getTarget(n-1, t, arr, dp);
            if(val)return t-(sum-t);
        }
	} 
};//T.C. = O(N*Sum*Sum/2), S.C. = O(N*Sum*sum/2) +O(Sum/2 * N)

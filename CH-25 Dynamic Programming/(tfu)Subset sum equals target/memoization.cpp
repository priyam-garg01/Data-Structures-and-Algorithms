#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    bool isTarget(int idx, vector<int>& arr, int target, vector<vector<int>>& dp){
        if(target == 0)return true;
        if(idx == 0)return arr[idx] == target;
        if(dp[idx][target] != -1)return dp[idx][target];

        //Take
        bool pick = false;
        if(target >= arr[idx])pick = isTarget(idx-1, arr, target-arr[idx], dp);

        //Dont Take
        bool notPick = false;
        notPick = isTarget(idx-1, arr, target, dp);

        return dp[idx][target] = (pick || notPick);

    }
    
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        
        return isTarget(n-1, arr, target, dp);
    }
};//T.C. = O(N*target), S.C. = O(N*target) + O(N)
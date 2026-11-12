#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int mod = 1e9 + 7;
    int countSubsetSumK(int idx, vector<int>&arr, int sum, vector<vector<int>>& dp){
        
        // if(idx == 0){
        //     if(sum == 0)return 1;
        //     return sum == arr[0];
        // }
        // if(sum == 0)return dp[idx][sum] = 1;

    //Handling if arr element is zero too
    /*Removing if(sum == 0) return 1; is necessary.
Without it, when sum reaches 0 at idx > 0, the recursion continues down to idx == 0. This ensures any remaining 0 
elements are processed (since picking a 0 multiplies the number of valid subsets by 2).*/

        if(idx == 0){//Firstly idx should be checked then sum
            //Only sum == 0 base not can't satisfy the ans if the arr has '0' as element further on
            if(sum == 0 && arr[0] == 0)return dp[idx][sum] = 2;//->empty set and {0}
            // return sum == arr[0];
            else if(sum == 0 || sum == arr[0])return dp[idx][sum] = 1;
            else return dp[idx][sum] = 0;
        }

        if(dp[idx][sum] != -1)return dp[idx][sum];

        int notPick = countSubsetSumK(idx-1, arr, sum, dp);

        int pick = 0;
        if(sum >= arr[idx]) pick = countSubsetSumK(idx-1, arr, sum - arr[idx], dp);


        return dp[idx][sum] = (notPick + pick)%mod;
    }

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        return countSubsetSumK(n-1, arr, K, dp)%mod;
        
	}
};//T.C. = O(N*TARGET), S.C. = O(N*K) + O(N)
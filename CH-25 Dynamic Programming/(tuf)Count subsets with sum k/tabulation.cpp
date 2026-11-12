#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int mod = 1e9 + 7;

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // dp[0][0] = 1;
        // if(K >= arr[0])dp[0][arr[0]] = 1;
        // for(int i = 0; i < n; i++){
        //     dp[i][0] = 1;
        // }

        // for(int i = 1; i < n; i++){
        //     for(int t = 0; t < K + 1; t++){
        //         int notPick = dp[i-1][t];

        //         int pick = 0;
        //         if(t >= arr[i]) pick = dp[i-1][t-arr[i]];


        //         dp[i][t] = (notPick + pick)%mod;
        //     }
        // }

        dp[0][0] = 1;
        if(arr[0] == 0)dp[0][0] = 2;
        if(K >= arr[0] && arr[0] != 0)dp[0][arr[0]] = 1; 

        for(int i = 1; i < n; i++){
            for(int t = 0; t < K+1; t++){
                int notPick = dp[i-1][t];

                int pick = 0;
                if(t >= arr[i]) pick = dp[i-1][t-arr[i]];


                dp[i][t] = (notPick + pick)%mod;
            }
        }
        return dp[n-1][K];
	}
};//T.C. = O(N*TARGET), S.C. = O(N*TARGET)
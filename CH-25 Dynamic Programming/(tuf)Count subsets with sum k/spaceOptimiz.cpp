#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int mod = 1e9 + 7;

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<int> dp(K + 1, 0);
        vector<int> temp(K+1, 0);
        // dp[0] = 1;
        // for(int t = 1; t <= K; t++){
        //     dp[t] = t == arr[0];
        // }
        // temp[0] = 1;

        dp[0] = 1;
        if(arr[0] == 0)dp[0] = 2;
        if(K >= arr[0] && arr[0] != 0)dp[arr[0]] = 1; 
        

        for(int i = 1; i < n; i++){
            for(int t = 0; t < K + 1; t++){
                int notPick = dp[t];

                int pick = 0;
                if(t >= arr[i]) pick = dp[t-arr[i]];


                temp[t] = (notPick + pick)%mod;
            }
            dp = temp;
        }
        return dp[K];
	}
};//T.C. = O(N*TARGET), S.C. = O(2*TARGET)
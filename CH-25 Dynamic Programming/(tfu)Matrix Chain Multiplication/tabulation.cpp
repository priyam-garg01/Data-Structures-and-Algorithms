#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:

		int matrixMultiplication(vector<int>& nums){
            int n= nums.size();
            vector<vector<int>> dp(n, vector<int>(n+1, 0));

            for(int i = 0; i < n; i++){
                dp[i][i] = 0;
            }

            for(int i = n-1; i >= 1; i--){
                for(int j = i+1; j <= n-1; j++){//j will be be on the right of i that is greater than or equal to i
                    int mini = 1e9;
                    for(int k = i; k < j; k++){
                        int steps = nums[i-1]*nums[k]*nums[j];
                        steps += dp[i][k] + dp[k+1][j];
                        mini = min(mini, steps);
                    }
                    dp[i][j] = mini;
                }
            }
            return dp[1][n-1];
    	}
};/*T.C. = O(N^3), S.C. = O(N^2)*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
        int minMutilp(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
            if(i == j)return 0;//No multiplications for an array

            if(dp[i][j] != -1)return dp[i][j];
            int mini = INT_MAX;
            for(int k = i; k < j; k++){//K remains till j-1 as k+1 should not exceed arr len and also funct(j, j)will return zero while funct(j+1, j)might cause arrayIndexOutofBounds Error
                int steps = nums[i-1]*nums[k]*nums[j];//(rows(stMat))*(insection OR Partition index)*(col(endMat))
                steps += minMutilp(i, k, nums, dp) + minMutilp(k+1, j, nums, dp);
                mini = min(mini, steps);
            }

            return dp[i][j] = mini;
        }

		int matrixMultiplication(vector<int>& nums){
            int n= nums.size();
            vector<vector<int>> dp(n-1, vector<int>(n, -1));
            return minMutilp(1, n-1, nums, dp);
    	}
};//T.C. = O(N^3), S.C. = O(N^2 + N)
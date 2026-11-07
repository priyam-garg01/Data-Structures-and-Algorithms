#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallPathSum(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col < 0 || col >= matrix.size())return 1e9;
        if(dp[row][col] != 101)return dp[row][col];
        if(row == matrix.size()-1)return dp[row][col] = matrix[row][col];
        int d = matrix[row][col] + minFallPathSum(row+1, col, matrix, dp);

        int dL = matrix[row][col] + minFallPathSum(row+1, col-1, matrix, dp);

        int dR = matrix[row][col] + minFallPathSum(row+1, col+1, matrix, dp);

        return dp[row][col] = min(d, min(dL, dR));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = 0;
        int mini = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, 101));//as -100 <= matrix[i][j] <= 100

    // Base Case
        for(int col = 0; col < n; col++){
            dp[n-1][col] = matrix[n-1][col];
        }

        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col < n; col++){
                int d = matrix[row][col] + dp[row+1][col];

                int dL = 1e9;
                if(col > 0)dL = matrix[row][col] + dp[row+1][col-1];

                int dR = 1e9;
                if(col < n-1)dR = matrix[row][col] + dp[row+1][col+1];

                dp[row][col] = min(d, min(dL, dR));
            }
        }
        for(int col = 0; col < n; col++){
            mini = min(dp[0][col], mini);
        }

        return mini;
    }
};/*T.C. = O(N*N) + O(2N), S.C. = O(N*N)s*/
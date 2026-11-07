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

        for(int col = 0; col < n; col++){
            mini = min(mini, minFallPathSum(row, col, matrix, dp));
        }
        return mini;
    }
};/*T.C. = O(N*(N)) {NOT 3N, as each sub-prob takes O(1) time using memoization}
S.C. = O(N*N) + O(N)*/
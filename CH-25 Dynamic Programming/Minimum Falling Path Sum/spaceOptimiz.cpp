#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = 0;
        int mini = 1e9;
        vector<int> dp(n, 101);//as -100 <= matrix[i][j] <= 100

    // Base Case
        for(int col = 0; col < n; col++){
            dp[col] = matrix[n-1][col];
        }

        for(int row = n-2; row >= 0; row--){
            vector<int> temp(n, 101);
            for(int col = 0; col < n; col++){
                int d = matrix[row][col] + dp[col];

                int dL = 1e9;
                if(col > 0)dL = matrix[row][col] + dp[col-1];

                int dR = 1e9;
                if(col < n-1)dR = matrix[row][col] + dp[col+1];

                temp[col] = min(d, min(dL, dR));
            }
            dp = temp;
        }
        for(int col = 0; col < n; col++){
            mini = min(dp[col], mini);
        }

        return mini;
    }
};/*T.C. = O(N*N + 2N), S.C. = O(2N)*/
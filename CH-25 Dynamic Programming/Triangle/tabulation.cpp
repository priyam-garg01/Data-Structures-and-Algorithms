#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));


        //We went from (0, 0) to (n-1, n-1) in memoization top down app
        //Hence we will traverse from (n-1) to sum up to first row in tabulation with 
        //Base case: if(row == n-1)return triangle[row][idx];

        for(int i = 0; i < n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int row = n-2; row >= 0; row--){
            for(int col = row; col >= 0; col--){
                int d = 1e9;//Down movement
                int dR = 1e9;//Down and right movement

                d = triangle[row][col] + dp[row+1][col];
                dR = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(d, dR);
            }
        }

        return dp[0][0];
    }
};/*//We went from (0, 0) to (n-1, n-1) in the memoization top-down app.
//Hence we will traverse from (n-1) to sum up to the first row in tabulation with base case: if (row == n-1) return triangle[row][idx];
T.C. = O(N*N), S.C. = O(N*N)*/
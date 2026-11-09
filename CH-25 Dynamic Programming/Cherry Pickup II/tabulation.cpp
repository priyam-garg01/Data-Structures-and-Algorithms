#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxCherry(int r, int c1, int c2, vector<vector<int>>& grid, int m , int n,vector<vector<vector<int>>>& dp){
        if(r >= m || c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)return -1e9;
        if(dp[r][c1][c2] != -1)return dp[r][c1][c2];
        if(r == m-1){
            if(c1 == c2)return dp[r][c1][c2] = grid[r][c1];
            return dp[r][c1][c2] = grid[r][c1] + grid[r][c2];
        }

        int ans = -1e9;
        // int C1[] = {1, 0, -1};
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                ans = max(ans, maxCherry(r+1, c1+i, c2+j, grid, m, n, dp));
            }
        }

        if(c1 == c2)ans += grid[r][c1];
        else ans += grid[r][c1] + grid[r][c2];

        return dp[r][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)dp[m-1][i][j] = grid[m-1][j];
                else dp[m-1][i][j] = grid[m-1][i] + grid[m-1][j];
            }
        }
        for(int r = m-1; r >= 0; r--){
            for(int c1 = n-1; c1 >= 0; c1--){
                for(int c2 = n-1; c2 >= 0; c2--){
                    if(r == m-1)continue;
                    int ans = -1e9;
                    for(int i = -1; i < 2; i++){
                        for(int j = -1; j < 2; j++){
                          if(r+1 < m && c1+i < n && c1+i >= 0 && c2+j < n && c2+j >= 0)ans = max(ans, dp[r+1][c1+i][c2+j]);
                        }
                    }

                    if(c1 == c2)ans += grid[r][c1];
                    else ans += grid[r][c1] + grid[r][c2];

                    dp[r][c1][c2] = ans;
                }
            }
        }

        return dp[0][0][n-1];
    }
};/*T.C. = O(M*N*N), S.C. = O(M*N*N)*/
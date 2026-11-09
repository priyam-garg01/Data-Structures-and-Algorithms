#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)dp[i][j] = grid[m-1][j];
                else dp[i][j] = grid[m-1][i] + grid[m-1][j];
            }
        }
        for(int r = m-2; r >= 0; r--){
            vector<vector<int>> temp(n, vector<int>(n, -1));
            for(int c1 = n-1; c1 >= 0; c1--){
                for(int c2 = n-1; c2 >= 0; c2--){
                    // if(r == m-1)continue;
                    int ans = -1e9;
                    for(int i = -1; i < 2; i++){
                        for(int j = -1; j < 2; j++){
                          if(c1+i < n && c1+i >= 0 && c2+j < n && c2+j >= 0)ans = max(ans, dp[c1+i][c2+j]);
                        }
                    }

                    if(c1 == c2)ans += grid[r][c1];
                    else ans += grid[r][c1] + grid[r][c2];

                    temp[c1][c2] = ans;
                }
            }
                dp = temp;
        }

        return dp[0][n-1];
    }
};/*T.C. = O(M*N*N), S.C. = O(N*N)*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));

        dp[n-1][n-1] = grid[n-1][n-1];

    for(int k = 2*(n-1)-1; k >= 0; k--){
        vector<vector<int>> temp(n, vector<int>(n, -1e9));
        for(int r1 = n-1; r1 >= 0; r1--){
            for(int r2 = n-1; r2 >= 0; r2--){
                int c1 = k - r1;
                int c2 = k - r2;
                
                if(c2<0 || c2 >= n)continue;
                if(c1 < 0 || c1 >= n)continue;
                if(r1 == n-1 && c1 == n-1){
                    temp[r1][r2] = grid[n-1][n-1];
                    continue;
                }
                if(grid[r1][c1] == -1 || grid[r2][c2] == -1){
                    temp[r1][r2] = -1e9;
                    continue;
                }
                int ans = -1e9;
                for(int d1 = 0; d1 <= 1; d1++){
                    for(int d2 = 0; d2 <= 1; d2++){
                        int nr1 = r1+d1;
                        int nr2 = r2+d2;
                        if(nr1 < n && nr2 < n){
                            ans = max(ans, dp[nr1][nr2]);
                        }
                    }
                }
                if(ans < 0){
                    dp[r1][r2] = -1e9;
                    continue;
                }
                if(r1 == r2 && c1 == c2)ans += grid[r1][c1];
                else ans += grid[r1][c1] + grid[r2][c2];

                temp[r1][r2] = ans;
            }
        }
        dp = temp;
    }

        if(dp[0][0] < 0)return 0;
        return dp[0][0];
    }
};/*T.C. = O(N*N*N), S.C. = O(N*N)
The DP state transitions from step k to step k+1.
Step k=2(n−1) is the destination (n−1,n−1). Its value depends on no future steps, making it the base case.
Step k depends on values already calculated at step k+1.
Iterating backwards from k=2(n−1)−1 down to 0 ensures step k+1 (stored in dp) is computed before computing step k (stored in temp).*/
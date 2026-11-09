#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        dp[n-1][n-1][n-1] = grid[n-1][n-1];

    for(int r1 = n-1; r1 >= 0; r1--){
        for(int c1 = n-1; c1 >= 0; c1--){
            for(int r2 = n-1; r2 >= 0; r2--){
                int c2 = r1+c1-r2;
                if(c2<0 || c2 >= n)continue;

                if(r1 == n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1) {
                    dp[r1][c1][r2] = grid[n-1][n-1];
                    continue;
                }
                if(grid[r1][c1] == -1 || grid[r2][c2] == -1){
                    dp[r1][c1][r2] = -1e9;
                    continue;
                }
                int DD = -1e9;
                //Person 1 & 2 down
                if(r1+1 < n && r2+1 < n) DD = dp[r1+1][c1][r2+1];

                int RR = -1e9;
                //Person 1 & 2 right
                if(c1+1 < n)RR = dp[r1][c1+1][r2];

                int DR = -1e9;
                //Person 1 Down and 2 right
                if(r1+1 < n)DR = dp[r1+1][c1][r2];

                int RD = -1e9;
                //Person 1 right and 2 down
                if(c1+1 < n && r2+1 < n)RD = dp[r1][c1+1][r2+1];

                int ans;
                ans = max(DD, max(RD, max(RR, DR)));
                if(ans < 0){
                    dp[r1][c1][r2] = -1e9;
                    continue;
                }
                if(r1 == r2 && c1 == c2)ans += grid[r1][c1];
                else ans += grid[r1][c1] + grid[r2][c2];

                dp[r1][c1][r2] = ans;
            }
        }
    }

        if(dp[0][0][0] < 0)return 0;
        return dp[0][0][0];
    }
};/*T.C. = O(N^3), S.C. = O(N^3)*/
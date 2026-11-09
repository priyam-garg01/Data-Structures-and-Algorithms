#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxCherry(int r1, int c1, int r2, vector<vector<int>>& grid, int n, vector<vector<vector<int>>>& dp){
        int c2 = r1 + c1 - r2;

        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)return -1e9;

        if(r1 == n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1)       return dp[r1][c1][r2] = grid[n-1][n-1];

        if(dp[r1][c1][r2] != -1)return dp[r1][c1][r2];
        
        //Person 1 & 2 down
        int DD = maxCherry(r1+1, c1, r2+1, grid, n, dp);

        //Person 1 & 2 right
        int RR = maxCherry(r1, c1+1, r2, grid, n, dp);

        //Person 1 Down and 2 right
        int DR = maxCherry(r1+1, c1, r2, grid, n, dp);

        //Person 1 right and 2 down
        int RD = maxCherry(r1, c1+1, r2+1, grid, n, dp);
        int ans;
        if(r1 == r2 && c1 == c2)ans = grid[r1][c1];
        else ans = grid[r1][c1] + grid[r2][c2];

        ans += max(DD, max(RD, max(RR, DR)));

        return dp[r1][c1][r2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        //This is a 3D grid as we take 2 persons starting from the same point 0, 0 and move them simultaneously
        int cherryCt = maxCherry(0, 0, 0, grid, n, dp);
        if(cherryCt < 0)return 0;
        return dp[0][0][0];
    }
};/*Remove c2 from the parameter list using int c2 = r1 + c1 - r2;.
Add memoization with a 3D DP array of size [N][N][N]. as noting only one person's indices will result to nothing
T.C. = O(N*N*N), S.C. = O(N*N*N) + O(2N)*/
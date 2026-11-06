#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minSum(int idx, int row, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
        if(row >= n || idx >= row + 1)return 0;
        //if(row == n-1)return traingle[row][idx];
        if(dp[row][idx] != -1)return dp[row][idx];
        
        int d = 1e9;//Down movement
        int dR = 1e9;//Down and right movement

        d = triangle[row][idx] + minSum(idx, row+1, triangle, n, dp);
        dR = triangle[row][idx] + minSum(idx+1, row+1, triangle, n, dp);

        return dp[row][idx] = min(d, dR);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int idx = 0;
        int row = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minSum(idx, row, triangle, n, dp);
    }
};/*T.C. = O(N*N), S.C. = O(N) + O(N*N)*/
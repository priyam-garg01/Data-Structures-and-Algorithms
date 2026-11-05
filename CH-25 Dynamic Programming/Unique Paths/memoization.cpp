#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int m, int n, vector<vector<int>>& dp){
        if(m == 0 && n == 0){
            return 1;
        }
        if(dp[m][n] != 0)return dp[m][n];

        int up = 0;
        int right = 0;

        if(m > 0)up = countPaths(m-1, n, dp);
        if(n > 0)right = countPaths(m, n-1, dp);

        return dp[m][n] = up + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return countPaths(m-1, n-1, dp);
    }
};/*T.C. = O(M*N), S.C. = O(M*N + M-1 + N-1)
Dp stores the number of unique paths from (0, 0)*/
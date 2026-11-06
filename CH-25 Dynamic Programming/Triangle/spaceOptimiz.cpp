#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();


        //We went from (0, 0) to (n-1, n-1) in memoization top down app
        //Hence we will traverse from (n-1) to sum up to first row in tabulation with base case: if(row == n-1)return triangle[row][idx];
        //For space Optimiz we need only the prev row elemets

        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++){
            dp[i] = triangle[n-1][i];
        }

        for(int row = n-2; row >= 0; row--){
            vector<int> temp(n, -1);
            for(int col = row; col >= 0; col--){
                int d = 1e9;//Down movement
                int dR = 1e9;//Down and right movement

                d = triangle[row][col] + dp[col];
                dR = triangle[row][col] + dp[col+1];

                temp[col] = min(d, dR);
            }
            dp = temp;
        }

        return dp[0];
    }
};/*T.C. = O(N*N), S.C. = O(2N)*/
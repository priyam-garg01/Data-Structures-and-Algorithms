#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 1;
        vector<int> dp(n, 0);
//We only move left and upwards to check the prev elements so since nested for loop executes column wise we need only the prev row elements
        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    // dp[j] = 1;we talk about the curr vector here
                    temp[j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;

                if(i > 0)up = dp[j];//Upwards elem is in dp vector
                if(j > 0)left = temp[j-1];//left already stored in temp

                temp[j] = up + left;
            }
            dp = temp;
        }

        return dp[n-1];
    }
};/*T.C. = O(M*N), S.C. = O(N)
Dp stores the number of unique paths from (0, 0)*/
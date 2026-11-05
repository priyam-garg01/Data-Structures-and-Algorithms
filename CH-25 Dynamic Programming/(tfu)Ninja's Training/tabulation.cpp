#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int days = matrix.size();
        int prevAct = 3;
        vector<vector<int>> dp(days, vector<int>(prevAct + 1, -1));

        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][1], matrix[0][0]);
        dp[0][0] = max(matrix[0][2], matrix[0][1]);
        dp[0][3] = max(matrix[0][1], max(matrix[0][0], matrix[0][2]));

        for(int Day = 1; Day < days; Day++){
            for(int prevAct = 0; prevAct < 4; prevAct++){
                for(int Act = 0; Act < 3; Act++){
                    if(Act == prevAct)continue;
                    int points = matrix[Day][Act] + dp[Day-1][Act];
                    dp[Day][prevAct] = max(points, dp[Day][prevAct]);
                }

            }
        }
        
        return dp[days-1][3];
    }//T.C. = O(N*4*3), S.C. = O(N*4);
};
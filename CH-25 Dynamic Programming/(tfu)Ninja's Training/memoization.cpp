#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(int Day, int prevAct, vector<vector<int>>& dp,vector<vector<int>>& matrix){
        if(Day < 0)return 0;
        if(dp[Day][prevAct] != -1)return dp[Day][prevAct];
        int Act1 = 0;
        int Act2 = 0;
        int Act3 = 0;

        if(prevAct != 0)Act1 = matrix[Day][0] + maxPoints(Day-1, 0, dp,  matrix);
        if(prevAct != 1)Act2 = matrix[Day][1] + maxPoints(Day-1, 1, dp, matrix);
        if(prevAct != 2)Act3 = matrix[Day][2] + maxPoints(Day-1, 2, dp, matrix);

        int maxi = max(Act1, Act2);

        return dp[Day][prevAct] = max(maxi, Act3);
    }


    int ninjaTraining(vector<vector<int>>& matrix) {
        int days = matrix.size();
        int prevAct = 3;
        vector<vector<int>> dp(days, vector<int>(4, -1));
        return maxPoints(days-1, prevAct, dp, matrix);
    }
};
class Solution {
public:
    int maxPoints(int Day, int prevAct, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        int maxi = 0;
        if(dp[Day][prevAct] != -1)return dp[Day][prevAct];
        if(Day == 0){
            for(int i = 0; i < 3; i++){
                if(i == prevAct)continue;
                maxi = max(maxi, matrix[0][i]);
            }
            return maxi;
        }
        
        for(int i = 0; i < 3; i++){
            if(i == prevAct)continue;
            maxi = max(matrix[Day][i] + maxPoints(Day-1, i, dp, matrix), maxi);
        }

        return dp[Day][prevAct] = maxi;
    }


    int ninjaTraining(vector<vector<int>>& matrix) {
        int days = matrix.size();
        int prevAct = 3;
        vector<vector<int>> dp(days, vector<int>(prevAct + 1, -1));
        return maxPoints(days-1, prevAct, dp, matrix);
    }
};/*T.C. = O(N*4)*3 , S.C. = O(N) + O(N*4)*/
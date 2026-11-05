#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int days = matrix.size();
        int prevAct = 3;
        // vector<vector<int>> dp(days, vector<int>(prevAct + 1, -1));
        vector<int> prevs(prevAct+1, 0);
        prevs[1] = max(matrix[0][0], matrix[0][2]);
        prevs[0] = max(matrix[0][1], matrix[0][2]);
        prevs[2] = max(matrix[0][0], matrix[0][1]);
        prevs[3] = max(matrix[0][1], max(matrix[0][0], matrix[0][2]));

        for(int Day = 1; Day < days; Day++){
            vector<int> newVals(4, 0);
            for(int prevAct = 0; prevAct < 4; prevAct++){
                for(int Act = 0; Act < 3; Act++){
                    if(Act == prevAct)continue;
                    int points = matrix[Day][Act] + prevs[Act];
                    newVals[prevAct] = max(points, newVals[prevAct]);
                }
            }
            prevs = newVals;
        }
        
        return prevs[3];
    }//T.C. = O(N*(prevAct)*(Act)), S.C. = O(prevAct*2);
};
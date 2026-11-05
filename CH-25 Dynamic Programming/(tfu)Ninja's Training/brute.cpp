/*A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.

Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.

Example 1:
Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]

Output: 210

Explanation:

Day 1: fighting practice = 70

Day 2: stealth training = 50

Day 3: fighting practice = 90

Total = 70 + 50 + 90 = 210

This gives the optimal points.

Example 2:
Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]

Output: 290

Explanation:

Day 1: running = 70

Day 2: stealth training = 20

Day 3: running = 200

Total = 70 + 20 + 200 = 290

This gives the optimal points.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(int Day, int prevAct, vector<vector<int>>& matrix){
        if(Day < 0)return 0;

        int Act1 = 0;
        int Act2 = 0;
        int Act3 = 0;

        if(prevAct != 0)Act1 = matrix[Day][0] + maxPoints(Day-1, 0, matrix);
        if(prevAct != 1)Act2 = matrix[Day][1] + maxPoints(Day-1, 1, matrix);
        if(prevAct != 2)Act3 = matrix[Day][2] + maxPoints(Day-1, 2, matrix);

        int maxi = max(Act1, Act2);

        return max(maxi, Act3);
    }


    int ninjaTraining(vector<vector<int>>& matrix) {
        int days = matrix.size();
        int prevAct = 3;
        return maxPoints(days-1, prevAct, matrix);
    }
};//T.C. = O(2^N), S.C. = O(N) 

class Solution {
public:
    int maxPoints(int Day, int prevAct, vector<vector<int>>& matrix){
        int maxi = 0;
        if(Day == 0){
            for(int i = 0; i < 3; i++){
                if(i == prevAct)continue;
                maxi = max(maxi, matrix[0][i]);
            }
            return maxi;
        }
        
        for(int i = 0; i < 3; i++){
            if(i == prevAct)continue;
            maxi = max(matrix[Day][i] + maxPoints(Day-1, i, matrix), maxi);
        }

        return maxi;
    }


    int ninjaTraining(vector<vector<int>>& matrix) {
        int days = matrix.size();
        int prevAct = 3;
        return maxPoints(days-1, prevAct, matrix);
    }
};

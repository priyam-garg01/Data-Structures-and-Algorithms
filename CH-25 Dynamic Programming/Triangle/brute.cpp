/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 */

#include<bits/stdc++.h>
using namespace std;
//B1
class Solution {
public:

    int minSum(int idx, int n, vector<vector<int>>& triangle){
        if(n == 0)return triangle[0][0];
        if(idx < 0)return 1e9;
        int up = 1e9;
        int up_left = 1e9;

        if(idx < triangle[n].size()){
            up = triangle[n][idx] + minSum(idx, n-1, triangle);
            up_left = triangle[n][idx] + minSum(idx-1, n-1, triangle);
        }
        return min(up, up_left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int miniSum = 1e9;
        for(int i = 0; i < triangle[n-1].size(); i++){
           int sum = minSum(i, n-1, triangle);
           miniSum = min(sum, miniSum);
        }//We get the min idx from above

        return miniSum;
    }
};/*T.C. = O(N * 2^(N)), S.C. = O(N*N) + O(N)*/
//B2
class Solution {
public:

    int minSum(int idx, int row, vector<vector<int>>& triangle, int n){
        if(row >= n || idx >= row + 1)return 0;

        int d = 1e9;//Down movement
        int dR = 1e9;//Down and right movement

        d = triangle[row][idx] + minSum(idx, row+1, triangle, n);
        dR = triangle[row][idx] + minSum(idx+1, row+1, triangle, n);

        return min(d, dR);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int idx = 0;
        int row = 0;

        return minSum(idx, row, triangle, n);
    }
};/*Brute Force: Starting from the base element, as if not, we would have to start with each element in the lowest row
T.C. = O(2^N), S.C. = O(N)*/

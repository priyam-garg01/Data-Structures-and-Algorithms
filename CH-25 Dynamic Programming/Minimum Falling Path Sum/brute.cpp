/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 
Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallPathSum(int row, int col, vector<vector<int>>& matrix){
        if(col < 0 || col >= matrix.size())return 1e9;
        if(row == matrix.size()-1)return matrix[row][col];

        int d = matrix[row][col] + minFallPathSum(row+1, col, matrix);

        int dL = matrix[row][col] + minFallPathSum(row+1, col-1, matrix);

        int dR = matrix[row][col] + minFallPathSum(row+1, col+1, matrix);

        return min(d, min(dL, dR));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = 0;
        int mini = 1e9;
        for(int col = 0; col < n; col++){
            mini = min(mini, minFallPathSum(row, col, matrix));
        }
        return mini;
    }
};/*T.C. = O(N*3^(N)), S.C. = O(N)*/
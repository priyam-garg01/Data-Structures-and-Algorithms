/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100



Part-2: Where a matrix is given with obstacle coordinates just put that path traversal to zero*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int m, int n){
        if(m == 0 && n == 0){
            return 1;
        }

        int up = 0;
        int right = 0;

        if(m > 0)up = countPaths(m-1, n);
        if(n > 0)right = countPaths(m, n-1);

        return up + right;
    }

    int uniquePaths(int m, int n) {

        return countPaths(m-1, n-1);
    }
};/*T.C. = O(2^(M*N)), S.C. = O(M*N) + O(M-1 + N-1)
*/
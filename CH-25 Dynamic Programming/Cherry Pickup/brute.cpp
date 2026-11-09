/*You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

Example 1:


Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxCherry(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, int n){
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)return -1e9;
        if(r1 == n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1)return grid[n-1][n-1];

        //Person 1 & 2 down
        int DD = maxCherry(r1+1, c1, r2+1, c2, grid, n);

        //Person 1 & 2 right
        int RR = maxCherry(r1, c1+1, r2, c2+1, grid, n);

        //Person 1 Down and 2 right
        int DR = maxCherry(r1+1, c1, r2, c2+1, grid, n);

        //Person 1 right and 2 down
        int RD = maxCherry(r1, c1+1, r2+1, c2, grid, n);
        int ans;
        if(r1 == r2 && c1 == c2)ans = grid[r1][c1];
        else ans = grid[r1][c1] + grid[r2][c2];

        ans += max(DD, max(RD, max(RR, DR)));

        return  ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>& grid1 = grid;

        //This is a 3D grid as we take 2 persons starting from the same point 0, 0 and move them simultaneously
        int cherryCt = maxCherry(0, 0, 0, 0, grid1, n);
        if(cherryCt < 0)return 0;
        return cherryCt;
    }
};/*//This is a 3D grid as we take 2 persons starting from the same point 0, 0 and move them simultaneously tracking their positions as 2 persons moving from same point will have 4 different combinations at each step
T.C. = O(4^(N)), S.C. = O(2N)
NOTE: there is no need of a copy grid as we donot make any changes in it*/
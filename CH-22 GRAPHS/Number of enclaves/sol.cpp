/*You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 */class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>& vis, int delRow[], int delCol[]){
            vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i];
        if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow, ncol, grid, vis, delRow, delCol);
            } 
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //We want the number of 1's that are completely surrounded by zero
        //First we walk off the boundary and perform a dfs traversal to each 1's so that they all are visited
        //Then we walk off to the middle 1's ones and count them
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            if(!vis[i][0] grid[i][0] == 1){
                dfs(i, 0, grid, vis, delRow, delCol);
            }
        }
        for(int i = 0; i < m; i++){
            if(!vis[i][n-1] grid[i][n-1] == 1){
                dfs(i, n-1, grid, vis, delRow, delCol);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[0][i] grid[0][i] == 1){
                dfs(0, i, grid, vis, delRow, delCol);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[m-1][i] grid[m-1][i] == 1){
                dfs(m-1, i, grid, vis, delRow, delCol);
            }
        }
        int ct = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vis[i][j] = 1;
                    ct++;
                }
            }
        }
    return ct;
    }
// };T.C. = 4*O(M*N), S.C. = O(M*N);
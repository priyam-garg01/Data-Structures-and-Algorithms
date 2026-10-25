/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3*/
class Solution {
public:

    void bfsTrav(int row, int col, vector<vector<char>>& grid,       vector<vector<int>>& vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            pair<int, int> p = q.front();
            row = p.first;
            col = p.second;
            q.pop();        
//Leetcode checks links only for 4 directions doesnot include diagonals to be links
    //     for(int delrow = -1; delrow <= 1; delrow++){
    //         for(int delcol = -1; delcol <= 1; delcol++){
    //             int nrow = row + delrow;
    //             int ncol = col + delcol;
    // if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
    //     q.push({nrow, ncol});
    //     vis[nrow][ncol] = 1;
    // }
    //         }
    //     }
        if(col < grid[row].size() - 1 && grid[row][col + 1] == '1' && !vis[row][col + 1]){
                q.push({row, col + 1});
                vis[row][col + 1] = 1;
            }
        if(row < grid.size() - 1 && grid[row + 1][col] == '1' && !vis[row + 1][col]){
            q.push({row + 1, col});
            vis[row + 1][col] = 1;
            }
        if(row > 0 && grid[row - 1][col] == '1' && !vis[row - 1][col]){
            q.push({row - 1, col});
            vis[row - 1][col] = 1;
            }
        if(col > 0 && grid[row][col - 1] == '1' && !vis[row][col - 1]){
            q.push({row, col - 1});
            vis[row][col - 1] = 1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));//Here we take the visited vector same as the size of the matrix
        int ct = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfsTrav(i, j, grid, vis);
                    ct++;
                }
            }
        }
        return ct;
    }
};/*Using the concept of all directional movement from the matrix and syncing it with the DFS traversal of the graph
T.C. = O(N*N) + O(N*N*4){4 directions travelled for every node in case all are 1}{A single BFS TRAVERSAL}
S.C. = O(N*N) + O(N*N){Every node is connected}*/
class Solution {
public:

    void dfsTrav(vector<vector<char>>& grid, pair<int, int> p,       vector<vector<int>>& vis){
        int row = p.first;
        int col = p.second;
        vis[row][col] = 1;

        if(col < grid[row].size() - 1 && grid[row][col + 1] == '1' && !vis[row][col + 1]){
            dfsTrav(grid, {row, col + 1}, vis);
        }
        if(row < grid.size() - 1 && grid[row + 1][col] == '1' && !vis[row + 1][col]){
            dfsTrav(grid, {row + 1, col}, vis);
        }
        if(row > 0 && grid[row - 1][col] == '1' && !vis[row - 1][col]){
            dfsTrav(grid, {row - 1, col}, vis);
        }
        if(col > 0 && grid[row][col - 1] == '1' && !vis[row][col - 1]){
            dfsTrav(grid, {row, col - 1}, vis);
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
                    dfsTrav(grid, {i, j}, vis);
                    ct++;
                }
            }
        }
        return ct;
    }
};/*T.C. = O(N*N) + O(N*N*) 4) {No of times the DFS call is made for each node taking worst case as every node has val 1},
 S.C. = O(N*N) + O(N*N){SKEWED PATTERN (Every node is connected)}*/
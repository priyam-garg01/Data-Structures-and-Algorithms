class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[], queue<pair<int, int>> q){

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i];
        if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            vis[nrow][ncol] = 1;
            q.push({nrow, ncol});
                } 
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

        int delRow[] = {0, 1, -1, 0};
        int delCol[] = {1, 0, 0, -1};
        // for(int i = 0; i < m; i++){
        //     if(!vis[i][0] && grid[i][0] == 1){
        //         bfs(i, 0, grid, vis, delRow, delCol);
        //     }
        // }
        // for(int i = 0; i < m; i++){
        //     if(!vis[i][n-1] && grid[i][n-1] == 1){
        //         bfs(i, n-1, grid, vis, delRow, delCol);
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     if(!vis[0][i] && grid[0][i] == 1){
        //         bfs(0, i, grid, vis, delRow, delCol);
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     if(!vis[m-1][i] && grid[m-1][i] == 1){
        //         bfs(m-1, i, grid, vis, delRow, delCol);
        //     }
        // }
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        bfs(grid, vis, delRow, delCol, q);

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
};
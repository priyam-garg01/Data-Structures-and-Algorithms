/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]*/
class Solution {
public:
    void bfs(queue<pair<pair<int, int>, int>> q, vector<vector<int>>& ans, vector<vector<int>>& mat, vector<vector<int>>& vis, int delRow[], int delCol[]){
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            ans[row][col] = steps;
            q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size() && !vis[nrow][ncol]){
                q.push({{nrow, ncol}, steps + 1});//++steps increments every time a direction is changed 4 times which should be 1 time
                vis[nrow][ncol] = 1;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n , 0));
        vector<vector<int>> ans = vis;
        queue<pair<pair<int, int>, int>> q;
        
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }//We store all the zero in the queue and apply bfs traversal on each to get ans 
        }
        bfs(q, ans, mat, vis, delRow, delCol);

        return ans;
    }
};/*Can be done by BFS easily, as it travels to multiple levels with the same past data
T.C. = O(M*N) + 4*O(M*N) == O(M*N), S.C. = 2*O(M*N) = O(M*N)*/
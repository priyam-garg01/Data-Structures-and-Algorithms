/*You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]*/
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[], int delCol[]){
        //4*O(M*N)
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
    if(nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, board, vis, delRow, delCol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
//if the O's are at edges they cannot be captured, also the region which is connected to edge O's also can't be captured
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if((i == 0 || j == 0 || j == n - 1 || i == m - 1) && !vis[i][j] && board[i][j] == 'O'){
        //             dfs(i, j, board, vis, delRow, delCol);
        //             }
        //             else if(!vis[i][j] && board[i][j] == 'O'){
        //                 board[i][j] = 'X';
        //                 vis[i][j] = 1;
        //             }
        //         }
        //     }
        /*This is faulty as earlier many O's may been already converted to X before reching their corners
          */
        //   So we first travel corners
          for(int i = 0; i < m; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis, delRow, delCol);
            }
          }
          for(int i = 0; i < m; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis, delRow, delCol);
            }
          }
          for(int i = 0; i < n; i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0, i, board, vis, delRow, delCol);
            }
          }
          for(int i = 0; i < m; i++){
            if(!vis[i][n - 1] && board[i][n - 1] == 'O'){
                dfs(i, n - 1, board, vis, delRow, delCol);
            }
          }
          for(int i = 0; i < n; i++){
            if(!vis[m - 1][i] && board[m - 1][i] == 'O'){
                dfs(m - 1, i, board, vis, delRow, delCol);
            }
          }

          for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
          }

            return ;
        }
    
};/*First traversing the corners and marking via dfs and visit and the inside elements and replacing them
T.C. = O(M*N), S.C. = O(M*N)*/
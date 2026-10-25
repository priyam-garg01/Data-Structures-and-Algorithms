/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only 
happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.*/
class Solution {
public:
    
   
    int orangesRotting(vector<vector<int>>& grid) {

        /*0 --> empty cell
        1 --> fresh orange
        2 --> rotten orange
        */
//If we find a val 2 we do the bfs to mark all of its adjacent mangoes as rotten (2)
//At last if we find any mango as 1 we return -1
    int m = grid.size();
    int n = grid[0].size();
    int vis[m][n];
    queue<pair<pair<int, int>, int>> q;
    //Queue notes the row col pair and the time that is the number of traversal done by a rotten orage to '1' noted orange

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;//as we have not marked in begining
            }
        }
    }
    //BFS TRAVERSAL
    int tm = 0;
    int delRow[] = {1, 0, -1, 0};
    int delCol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(t, tm);
        q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
        q.push({{nrow, ncol}, t + 1});
        vis[nrow][ncol] = 2;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] != 2 &&grid[i][j] == 1)return -1;
            }
        }
        return tm;
    }
};/*Using the bfs traversal as in bfs we move parallely {simultaneously} to all the nodes with same distance getting the reach of every rotten orange to its neighbouring fresh orange 
T.C. = O(N*M), S.C. = O(N*M)*/
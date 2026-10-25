/*Given a grid grid[][] of size n × m, consisting of characters 'L' and 'W', where 'L' represents Land and 'W' represents Water, find the number of distinct islands in the grid. An island is a group of one or more land cells connected horizontally or vertically.

Two islands are considered distinct if their shapes are different.
Two islands have the same shape if one can be translated to match the other exactly. Rotation and reflection are not allowed.
Examples :

Input: grid[][] = [['L', 'W', 'W'], ['W', 'W', 'L'], ['L', 'W', 'W']]
Output: 1
Explanation: The grid contains three islands. All these islands have the same shape (a 1 × 1 block of land), so they are counted as a single distinct island.
 
Input: grid[][] = [['L', 'L', 'W', 'L', 'L'], ['L', 'W', 'W', 'W', 'W'], ['W', 'W', 'L', 'W', 'L'], ['L', 'W', 'W', 'L', 'L']]
Output: 4
Explanation: There are five islands in the grid. Two islands have the same shape (a 1 × 1 block of land), while the other three have different shapes. Therefore, the number of distinct island shapes is 4.
*/
class Solution {
  public:
  
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& vec, int delRow[], int delCol[], int row0, int col0){
        vis[row][col] = 1;
        // vec.push_back({row, col});We also have to store the difference of base node pair from the new nodes
        vec.push_back({row - row0, col - col0});             
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
        if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 'W'){
                dfs(nrow, ncol, grid, vis, vec, delRow, delCol, row0, col0);
            }
        }
    } 
    int countDistinctIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // unordered_set<vector<pair<int, int>>> st;
        /*In C++, std::unordered_set doesn't know how to hash complex 
        structures like std::vector<std::pair<int, int>> by default. If you try to 
        compile this, you'll get a giant wall of template errors.*/
        set<vector<pair<int, int>>> st;
        
        int delRow[] = {0, -1, 1, 0};
        int delCol[] = {-1, 0, 0, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 'W'){
                    vector<pair<int, int>> vec;//Stores the consective land cells location points
                    dfs(i, j, grid, vis, vec, delRow, delCol, i, j);
                    st.insert(vec);//Stores the unique islands
                }
            }
        }
        return st.size();
        
        
    }
};//T.C. = 4*O(M*N) + O(N*M*LOG(N*M)), S.C. = O(M*N) + O(M*N)
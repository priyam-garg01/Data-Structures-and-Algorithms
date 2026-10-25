/*Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).



Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).



The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.



Note :

In a path no cell can be visited more than once.
If there is no possible path then return empty vector.

Example 1

Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]

Output : [ "DDRDRR" , "DRDDRR" ]

Explanation : The rat has two different path to reach (3, 3).

The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).

The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

Example 2

Input : n = 2 , grid = [ [1, 0] , [1, 0] ]

Output : -1

Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).*/
class Solution{
    public:

void  pathfinder(int row, int col, vector<string> &ans, string s, vector<vector<int> > &grid, int n, vector<vector<int>> &visited){//We also need to create a visited arr to take care that we dont cross the same cell again
    
    //Base case
        if(col == n - 1 && row == n - 1){
            ans.push_back(s);
        }
// For moving we have to first check if our next step is 1


    //Going down
    if(row + 1 < n && visited[row + 1][col] == 0 && grid[row + 1][col] == 1){
        s.push_back('D');
        visited[row + 1][col] = 1;
        pathfinder(row + 1, col, ans, s, grid, n, visited);
        visited[row + 1][col] = 0;
        s.pop_back();
}

    //Going left
        if(col - 1 >= 0 && visited[row][col - 1] == 0 && grid[row][col - 1] == 1){
        s.push_back('L');
        visited[row][col - 1] = 1;
        pathfinder(row, col - 1, ans, s, grid, n, visited);
        visited[row][col - 1] = 0;
        s.pop_back();
}
    //Going right
        if(col + 1 < n && visited[row][col + 1] == 0 && grid[row][col + 1] == 1){
        s.push_back('R');
        visited[row][col + 1] = 1;
        pathfinder(row, col + 1, ans, s, grid, n, visited);
        visited[row][col + 1] = 0;
        s.pop_back();
}
    //Going up
        if(row -1 >= 0 && visited[row - 1][col] == 0 && grid[row - 1][col] == 1){
        s.push_back('U');
        visited[row-1][col] = 1;
        pathfinder(row-1, col, ans, s, grid, n, visited);
        visited[row-1][col] = 0;
        s.pop_back();
    }
}

    vector<string> findPath(vector<vector<int> > &grid) {
        if(grid[0][0] == 0)return {""};//if the 0, 0 index is 0 no starting pt
        int n = grid.size();

        vector<string> ans;
        string s;
        // vector<vector<int>> visited(n, (n,0));WRONG INITIATION
        vector<vector<int>> visited(n, vector<int>(n,0));
        //But starting cell is visited
        visited[0][0] = 1;
        pathfinder(0, 0, ans, s, grid, n, visited);
        return ans;
    }
};
// T.C. = O(4^(NxN)), S.C. = O(N^2)//First completing each col or row then moving to the latter
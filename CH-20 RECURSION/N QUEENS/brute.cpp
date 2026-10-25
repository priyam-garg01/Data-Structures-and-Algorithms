/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each 
other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate 
a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9*/

class Solution {
public:

bool safeToPlace(int row, int col, vector<string> &board, int n){
    int dupRow = row;
    int dupCol = col;

    //To check if we can place the queen or not, we check for three direction as we only need to check the previous rows and columns as next ones are already empty
    //1. Top-left diagonal
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')return false;
        row--;
        col--;   
    }
    row = dupRow;
    col = dupCol;
    //2. Horizontal left
    while(col >= 0){
        if(board[row][col] == 'Q')return false;
        col--;
    }
    col = dupCol;
    //3. Bottom left diagonal
    while(row < n && col >= 0){
        if(board[row][col] == 'Q')return false;
        row++;
        col--;
    }
    return true;
}

void placeQueens(int col, vector<string> &ds, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(ds);
        return;
    }


    for(int row = 0; row < n; row++){
        if(safeToPlace(row, col, ds, n)){
            ds[row][col] = 'Q';
            placeQueens(col + 1, ds, ans, n);
            ds[row][col] = '.';//When backtracking we need to reverse the Q 
        }
    }
    return;
}
    vector<vector<string>> solveNQueens(int n) {

      vector<vector<string>> ans;


      /*This creates n empty strings, not strings of length n.
So later,
ds[row][col] = 'Q';
causes out-of-bounds access.*/
    //   vector<string> board(n);//Board of size n
    
    vector<string> board(n, string(n, '.'));
    /*Now every row is initialized like:

....
....
....
....*/
    
    /*This is not needed as the initialization of board will be incorrect like that*/
    //   string s(n, '.');//String represents the column or row initiated with empty space
      placeQueens(0, board, ans, n); 

      return ans;
    }
};/*BRUTE FORCE: Firstly we initialize a board vector of strings of size n with every character as '.' representing the empty space
We need to place exactly one queen in one row, or one queen in one column and not meeting through the diagonals 
Then check by looping through the rows of each column one by one that is it safe to place a queen there or not by checking via the safe to place function which tells if the previous diagonal or horizontal has a queen placed to attack or not 
For backtracking we reinitialize that Q placed space to empty space
T.C. = O(N*(3N)), S.C. = O(N^2)*/
/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.*/
class Solution {
public:

bool isValid(vector<vector<char>> &board, char c, int row, int col, int n){
    for(int i = 0; i < n; i++){
        //check for all cols
        if(board[row][i] == c)
        return false;

        //check for all rows
        if(board[i][col] == c)
        return false;

        //check for that 3x3 particuoar matrix box
        /*row/3 and col/3 is necessary and cannot be canceled in multip with 3 as it determines the matrix box rows and columns index as there are total 9 3x3 matrices*/
        if(board[3*(row/3) + i/3][3*(col/3) + i % 3] == c)
        return false;
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.')continue;
                char c = board[i][j];
                board[i][j] = '.';//remove itself to correct in isValid
                if(!isValid(board, c, i, j, n)){
                    return false;
                } 
                board[i][j] = c;
            }
        }
        return true;
    }
};/*Brute force: check each and every character
T.C. = O(9*9*9) = O(729), S.C. = O(1)*/
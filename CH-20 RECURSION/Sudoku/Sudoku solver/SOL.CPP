/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.*/
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

bool completeSudoku(vector<vector<char>> &board, int n){
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, c, i, j, n)){
                            board[i][j] = c;
                        
                        if(completeSudoku(board, n) == true)//{After checking every character on all the empty spaces}
                            return true;
                        else 
                            board[i][j] = '.';//bactracking
                        }
                    }
                    return false;//if no character is being fit for that place
                }
            }
        }
    return true;//at last when every char is placed at its right place
}
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();//Board is always 9x9
        completeSudoku(board, n);
        return;
        
    }
};/*T.C. =O(9^m), S.C. = O(M), where m is the number of empty cells*/
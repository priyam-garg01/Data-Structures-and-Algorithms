class Solution {
public:


    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
       
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.')continue;
// since numbers are from 1 to 9 we have to convert them to index
                int num = board[i][j] - '1';//char - char can be done but char - int XXXX
                /*Characters are stored as ASCII values.

'1' = 49
'2' = 50
...
'9' = 57*/
                int boxInd = 3*(i/3) + j/3;    
    //From this we can find which box number contains what numbers
             if(row[i][num] || col[num][j] || box[boxInd][num]){
                    return false;
                }
                row[i][num] = true;
                col[num][j] = true;
                box[boxInd][num] = true;
            }
        }
        return true;
    }
};/* OPTIMAL:
/*For the Valid Sudoku problem, backtracking is unnecessary. The optimal solution scans the board once while maintaining:

9 sets (or boolean arrays) for rows
9 for columns
9 for 3×3 boxes
T.C. = O(9*9), S.C. = O((9*9)^3)*/
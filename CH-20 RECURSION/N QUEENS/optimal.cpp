class Solution {
public:



void placeQueens(int col, vector<string> &ds, vector<vector<string>> &ans, int n, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag){
    if(col == n){
        ans.push_back(ds);
        return;
    }

    for(int row = 0; row < n; row++){
        if(leftRow[row] == 0 && lowerDiag[row+col] == 0 && upperDiag[(n-1) + (col - row)] == 0){
            ds[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row+col] = 1;
            upperDiag[(n-1) + (col - row)] = 1;
            placeQueens(col + 1, ds, ans, n, leftRow, upperDiag, lowerDiag);
            ds[row][col] = '.';//When backtracking we need to reverse the Q 
            //here we also need to reverse the hash entries
            leftRow[row] = 0;
            lowerDiag[row+col] = 0;
            upperDiag[(n-1) + (col - row)] = 0;
        }
    }
    return;
}
    vector<vector<string>> solveNQueens(int n) {

      vector<vector<string>> ans;
    
      vector<string> board(n, string(n, '.'));
    // Here to check if placing a queen is safe or not we use hashing where we will store the horizontal rows of previouly placed queens and similarly for upper and lower diagonal as for lower diagonals it forms a a similar sum of row and column number {that is on the lower diagonal the sum of row and column index is same} and for upper diagonal it is same for{n-1 + (col-row){index}}
    //And the total size for diagonal hash is taken to be (2*n-1){including the zero sum too} as for horizontal it is n
    vector<int> leftRow(n, 0);
    vector<int> upperDiag(2*n - 1, 0);
    vector<int> lowerDiag(2*n - 1, 0);

placeQueens(0, board, ans, n, leftRow, upperDiag, lowerDiag); 

      return ans;
    }
};/* // Here to check if placing a queen is safe or not we use hashing where we will store the horizontal rows of previouly placed queens and similarly for upper and lower diagonal as for lower diagonals it forms a a similar sum of row and column number {that is on the lower diagonal the sum of row and column index is same} and for upper diagonal it is same for{n-1 + (col-row){index}}
    //And the total size for diagonal hash is taken to be (2*n-1){including the zero sum too} as for horizontal it is n
T.C. = O(N), S.C. = O(N) + O(2*(2*N - 1)) O(N){For board} + O(N^2) for ans*/
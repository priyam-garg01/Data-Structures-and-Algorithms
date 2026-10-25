class Solution {
  public:
    int findNumSmallest(int elem, vector<vector<int>> &matrix){
        int n = matrix.size();
        int ct = 0;
        // for(int i = 0; i < n; i++){//O(N^2)
        //     for(int j = 0; j < n; j++){
        //         if(elem >= matrix[i][j])ct++;
        //     }
        // }
        int row = 0;
        int col = n-1;
        while(row < n && col >= 0){//O(2n)
            if(matrix[row][col] > elem)col--;
            else if(matrix[row][col] <= elem){
                ct += col + 1;
                row++;
            }
        }
        return ct;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();

        /*Using the sorted condition that is 1st smallest element and last element is largest we know that our ans lies in between a[0][0], a[n-1][n-1] --> Binary search
        */
        int st = matrix[0][0];
        int end = matrix[n - 1][n - 1];
        int middle;
        while(st < end){//Log(max-min)
            middle = st +(end - st)/2;
            
            int ct = findNumSmallest(middle, matrix);

            if(ct < k)st = middle + 1;
            else if(ct >= k)end = middle;

        }
        return st;
    }
};/*T.C. = O(N(LOG(MAX-MIN)), S.C. = O(1)*/
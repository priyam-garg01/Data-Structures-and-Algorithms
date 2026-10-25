// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

class Solution{//GIVEN: that m*n == odd
public:
    int findMedian(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
    vector<int> lt;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            lt.push_back(matrix[i][j]);
        }
    }
        sort(lt.begin(), lt.end());
    
    return lt[m*n/2];
    }
};
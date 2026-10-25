/*Given a 2D matrix mat[][] of size n x m. Each row in the matrix is sorted in non-decreasing order, merge all the rows and return a single sorted array that contains all the elements of the matrix.

Examples :

Input: mat[][] = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]

Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Explanation: Merging all elements from the 3 sorted arrays and sorting them results in: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
Input: mat[][] = [[1, 2, 3, 4], [2, 2, 3, 4], [5, 5, 6, 6], [7, 8, 9, 9]]

Output: [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9] 
Explanation: Merging all elements from the 4 sorted arrays and sorting them results in:[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]
Constraints:
1 ≤ n * m ≤ 105
0 ≤ mat[i][j] ≤ 106*/
class Solution {
  public:
  
    void merge(vector<int>& v1, vector<int>& v2){
        vector<int> merged;
        int i, j; 
        i = j = 0;
    
        while(i < v1.size() && j < v2.size()){
            if(v1[i] > v2[j]){
                merged.push_back(v2[j++]);
            }
            else{
                merged.push_back(v1[i++]);
            }
        }
        
        while(i < v1.size()){
            merged.push_back(v1[i++]);
        }
        
        while(j < v2.size()){
            merged.push_back(v2[j++]);
        }
        v1 = merged;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        //Brute Force : Store the elements in a vector and then sort them T.C. = O(N*M) + O(N*M*(N*M)) = O(N^4)
        
        //Better: Take array one by one starting from the first 2 and then merge them
        
        int arrCt = mat.size();
        
        int arrSize = mat[0].size();
        
        vector<int> mergedArray = mat[0];
        for(int i = 1; i < arrCt; i++){//T.C. = O(N*(M*N)), S.C. = O(M*N) using heap sort this reduces to S.C. = O(1)
            merge(mergedArray, mat[i]);
        }
        return mergedArray;
    }
};
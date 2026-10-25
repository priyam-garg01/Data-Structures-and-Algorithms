/*Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 

Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.*/
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        /*Brute force store the n2 elements in a vector and sort it then return the k-1th element
            T.C. = O(N^2log(N^2)), S.C. = O(N^2)
        */
        //Take a priority queue iterate it through thr matrix and store the 3 smallest elements
        int n = matrix.size();
        priority_queue<int>pq;//O(K)
        
        for(int i = 0; i < n; i++){//O(N^2(logk))
            for(int j = 0; j < n; j++){
                if(pq.size() == k){
                    if(matrix[i][j] < pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
                else pq.push(matrix[i][j]);
            }
        }
        return pq.top();
    }
};/*T.C. = O(N^2(LOGK)), S.C. = O(K)*/
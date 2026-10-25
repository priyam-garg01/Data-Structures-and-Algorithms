/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1*/
class Solution {
public:

     int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        //We will use one loop to insert the Pse and Nse for each element and another to compute the area
        int maxArea = 0;
        stack<int> st;
        int element;
        int Nse;
        int Pse;
        for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
                element = arr[st.top()];//gives us the element whose next samller has been found
                st.pop();
                Nse = i;   
                Pse = st.empty() ? -1 : st.top();
                //if stack is empty its -1 else its st.top()
                int area = element*(Nse-Pse-1);
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }
        // If the elements are still there in the stack means there is no smaller element than them or the loop has ended
        while(!st.empty()){
            element = arr[st.top()];
            st.pop();
            Nse = n;
            Pse = st.empty() ? -1 : st.top();
        int area = element*(Nse-Pse-1);
            maxArea = max(maxArea, area);
        }
    return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n,0);
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            int area = 0;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                  //  height[j] += matrix[i][j];
                  height[j] += 1;//ASCII VAL OF CHAR '1' IS 49

                }
               
            }
            area = largestRectangleArea(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};/*T.C. = O(M*N) + O(M*(2N)) = O(3*M*N)
S.C. = O(M*N) + O(N){FOR THE STACK}
//We can also use a matrix prefixSum and store the total in it replacing with sum = 0 whenever it occurs
and doing the same for every prefixSum[i]*/
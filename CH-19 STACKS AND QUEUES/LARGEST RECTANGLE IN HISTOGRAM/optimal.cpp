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
};/*T.C. = O(N) + O(N){FOR PUSHING AND POPPING ELEMENTS}
S.C. = O(N)*/
/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.


Example 2:


Input: heights = [2,4]
Output: 4*/
class Solution {
public:

vector<int> prevSmallerElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0;i < n; i++){
        while(!st.empty() && arr[i] <= arr[st.top()])st.pop();

        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> nextSmallerElement(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] < arr[st.top()])st.pop();

        if(st.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}


    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
/*INTUITION: If the next or prev block has a height less than the current block the rectangle breaks thereby finding no area(as it becomes some random figure)*/
//And at the same time we have to access the previous and the next element for height comparison
//For this we will find out the index of Pse and Nse of each array element

        vector<int> Pse = prevSmallerElement(arr);

        vector<int> Nse = nextSmallerElement(arr);
        int area = 0;
        for(int i = 0; i < n; i++){
            int currArea = arr[i]*(Nse[i] - Pse[i] - 1);
            area = max(area, currArea);
        }

    return area;
    }
};/*INTUITION: If the next or prev block has a height less than the current block the rectangle breaks thereby finding no area(as it becomes some random figure)
//And at the same time we have to access the previous and the next element for height comparison
//For this we will find out the index of Pse and Nse of each array element
T.C. = O(2N) + O(2N) +O(N) = O(5N)
S.C. = O(2N) + O(2N) + O(2N) = O(6N) -> O(5N){IF SINGLE PUBLIC STACK IS USED}*/
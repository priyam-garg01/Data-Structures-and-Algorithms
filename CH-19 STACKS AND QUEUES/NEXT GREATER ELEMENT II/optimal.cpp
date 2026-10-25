class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
//Assume the array to a double linear array instead of circular where here will be hypothetical values repeating the same array elements after (n-1)th index
        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && nums[i%n] >= st.top())st.pop();

        if(st.empty()){
            if(i < n)ans[i] = -1;
            }
        else{
            if(i < n)ans[i] = st.top();
        }
            st.push(nums[i%n]);
        }
        return ans;
    }
};/*
OPTIMAL APPROACH:
Using the circular array to linear and combining it with the monotonic stack approach
Just make some change that elements will only be inserted when i < n
T.C. = O(2N) WRONG!!!!!!, S.C. = O(N) + O(N){ans space}
T.C. = O(2N) + O(N) + O(N){As a total of n elements can be removed from stack and n elements can be inserted into it so operating in stack requires 2n time complexity}*/
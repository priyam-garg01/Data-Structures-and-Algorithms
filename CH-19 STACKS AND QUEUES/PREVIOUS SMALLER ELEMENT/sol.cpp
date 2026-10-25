/*Given an array, find the nearest smaller element G[i] for every element A[i]
 in the array such that the element has an index smaller than i.
 Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]*/
    vector<int> Solution::prevSmaller(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[i] <= st.top())st.pop();
        
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}
/*Using monotonic increasing stack solution
// T.C. = O(3N){POP AND PUSH}, S.C. = O(N)*/

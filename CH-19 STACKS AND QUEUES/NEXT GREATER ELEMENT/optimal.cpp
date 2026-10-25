class Solution {
public:

/*INTUITION: LIKE POLES, a person standing and watching the poles situated in front only sees the poles which are greater of the first occuring poles and the ones in between which are smaller are not seen and ignored:
Similar to that we keep pushing the element which is greater than the one that are are already in stack after popping the smaller elements */
    vector<int> nextLargerElement(vector<int> arr) {
       int n = arr.size();
       stack<int> st;
       vector<int> ans(n);
       for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] >= st.top())st.pop();
        if(st.empty()){
            st.push(arr[i]);
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
            st.push(arr[i]);
        }
        }
       
       return ans;
    }
};
//T.C. = O(2N), S.C. = O(N) + O(N){FOR ANS}
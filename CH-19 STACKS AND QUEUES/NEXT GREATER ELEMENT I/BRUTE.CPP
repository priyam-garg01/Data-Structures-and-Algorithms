/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            int elem = nums1[i];
            int j = nums2.size()-1;
            stack<int> st;
            while(j >= 0 && nums2[j] != elem){
                st.push(nums2[j]);
                j--;
            }
            while(!st.empty()){
            if(st.top() > elem){
                ans.push_back(st.top());
                break;
            }
            st.pop();
        }
        if(ans.size() != i + 1)ans.push_back(-1);
        }
        return ans;
    }
};
/*T.C. = O(M*N) S.C = O(nums2.size())*/
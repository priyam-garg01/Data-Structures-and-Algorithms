class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top())st.pop();

            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        //from this we have recorded the next greater element of every element of nums2
        // now running a loop in nums1
        for(int i = 0; i < m; i ++){
            ans.push_back(mp[nums1[i]]);
        }
    return ans;
    }
};
/*Monotonic decreasiing stack sol
Note the next greater element of every element in the parent array that is nums2 and store it in a map by running a loop 
then by iterating in the child array push the ans in vector
T.C. = O(M + N), S.C. = O(2N) + O(N){for ans}*/
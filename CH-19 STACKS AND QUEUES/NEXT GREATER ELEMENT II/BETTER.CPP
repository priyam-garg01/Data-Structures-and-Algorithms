class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
//Assume the array to a double linear array instead of circular where here will be hypothetical values repeating the same array elements after (n-1)th index
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j <= n - 1 + i; j++){
                int index = j % n;
                if(nums[index] > nums[i]){
                    ans.push_back(nums[index]);
                    break;
                }
            }
            if(ans.size() != i + 1)ans.push_back(-1);
        }
        return ans;
    }
};/*BRUTE FORCE: common method of solving a circular array or converting a circular array into a linear array
T.C. = O(N^2), S.C. = O(N)*/
/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j ++){
                if(nums[j] > nums[i]){
                ans.push_back(nums[j]);
                break;
                }
            }
            if(ans.size() != i + 1){
                for(int k = 0; k < i; k++){
                    if(nums[k] > nums[i]){
                        ans.push_back(nums[k]);
                        break;
                    }
                }
            }
            if(ans.size() != i + 1){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};//BRUTE FORCE:
// T.C. = O(N^2), S.C. = O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxL = 0;
        
        int l = 0; int r = 0;
        int len;
        int ct_zero = 0;
        int index = 0;
        while(r < n){
            if(nums[r] == 0){
                ct_zero++;
            }
            if(ct_zero > k){
                // l = r - 1;
                // l doesnt point to r-1, it should point to the second last zero such that the zero count is still to max = k WRONG!!!!
                //we need to remove the first zero encountered
                // l = index + 1; WRONG!!
                //Move l untill a zero is encountered
                while(nums[l] != 0){
                    l++;
                }
                l++;//to remove the zero from the sliding window
                ct_zero = k;
            }
            len = r - l + 1;
            maxL = max(maxL, len);
            r++;
        }
        return maxL;
    }
};/*OPTIMAL:
T.C. = O(2N), S.C. = O(1)*/
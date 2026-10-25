class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxL = 0;
        
        int l = 0; int r = 0;
        int len;
        int ct_zero = 0;
        //if count > zeroes start moving both l and r so that the len remains maxL till ct becomes k by successively moving left pointer
        while(r < n){
            if(nums[r] == 0){
                ct_zero++;
            }
            if(ct_zero > k){
                if(nums[l] == 0){
                    ct_zero--;
                }
                    l++;
            }
            if(ct_zero <= k){
            len = r-l+1;
            maxL = max(maxL, len);
            }
            r++;
        }
        return maxL;
    }
};/*Most Optimal:
T.C. = O(N)
//if count > zeroes start moving both l and r so that the len remains maxL till 
ct becomes k by successively moving left pointer{here r is already moved becz after if the r++ 
statement is executed at the end*/
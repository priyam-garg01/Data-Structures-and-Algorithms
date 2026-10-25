class Solution {
public:

    int subarraysWithLessOrK(vector<int>& nums, int k){
        
        int n = nums.size();
        int count = 0;
        
        int l = 0; 
        int r = 0;
        unordered_map<int, int> mpp;
        //storing the integer and its freq

        while(r < n){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
                count += r - l + 1;
            }
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ct1 = subarraysWithLessOrK(nums, k);
        int ct2 = subarraysWithLessOrK(nums, k-1);

        return ct1 - ct2;
    }
};/*T.C. = O(4N), S.C. = O(2N)
Similar approach as Binary subarray with sum k*/
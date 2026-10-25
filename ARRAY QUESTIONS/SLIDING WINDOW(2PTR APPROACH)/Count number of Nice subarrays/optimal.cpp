class Solution {
public:

    int countSubarrayWithKodd(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;
       
        int l = 0;
        int r = 0;
        int odd = 0;
        while(r < n){
            if(nums[r] % 2)odd++;

            while(odd > k){
                if(nums[l] % 2){
                    odd--;
                }
                l++;
            }
            if(odd <= k){
                count += r - l + 1;
                r++;
                 }
            }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k){
        int ct1 = countSubarrayWithKodd(nums,k);
        int ct2 = countSubarrayWithKodd(nums,k - 1);
   
        return ct1-ct2;
    }
};/*Similar to binary subarray with sum
T.C. = O(4N), S.C. = O(1)
//Consider all 1's as odd and even as 0's as their remainder will equate to it when divided by 2*/
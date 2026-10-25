class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        if(goal < 0)return 0;//as binary doesnt contain -1
    int r = 0; int l = 0;
    int ct1 = 0;
    int sum = 0;
        while(r < n){//Number of subarrays less than or equal to goal
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }
                ct1 += r - l + 1;
                r++;
        }
        //number of subarrays less than goal == number of subarrays lesser than or equal to goal-1
        int ct2 = 0;
        if(goal == 0)ct2 = 0;
        else if(goal > 0){
        l = 0; r = 0; 
        sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal-1){//l may be greater than r but l < r if r is 0 and nums[0] = 1 but goal is 0 loop never runs
                sum -= nums[l];
                l++;
            }
                ct2 += r - l + 1;
                 r++;
        }
    }

        return ct1-ct2;
    }
};/*T.C. = O(4N), S.C. = O(1)
Cal the number of subarrays less than equal to goal and number of subarrays less than or equal to goal - 1 
and subtract them to get the ans*/
class Solution {
public:

int CountSubarraySumLessOrK(vector<int> & nums, int goal){
    int n = nums.size();
    if(goal < 0)return 0;//as binary doesnt contain -1
    int r = 0; int l = 0;
    int ct = 0;
    int sum = 0;
        while(r < n){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }
                ct += r - l + 1;
                r++;
        }
        return ct;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    
        int ct1 = CountSubarraySumLessOrK(nums,goal);
        int ct2 = CountSubarraySumLessOrK(nums,goal - 1);
    
        return ct1-ct2;
    }
};
/*Given an array nums of n integers. Return array of sum of all subsets of the array nums.

Output can be returned in any order.*/
class Solution {
  public:

void printSubseqSum(int index, vector<int> &ds, vector<int> &ans, int n, vector<int> &nums, int sum){

    if(index >= n){
        ans.push_back(sum);
        return;
    }

    ds.push_back(nums[index]);
    sum += nums[index];
    printSubseqSum(index + 1, ds, ans, n, nums, sum);
    

    ds.pop_back();
    sum -= nums[index];
    printSubseqSum(index + 1, ds, ans, n, nums, sum);
    return;
    
}
    vector<int> subsetSums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<int> ans;

        printSubseqSum(0, ds, ans, n, nums, 0);
        //for lexicographically correct order
        //sort it
        return ans;
    }
};
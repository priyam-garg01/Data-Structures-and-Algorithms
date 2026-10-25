class Solution {
  public:

void printSubseqSum(int index, vector<int> &ds, vector<vector<int>> &ans, int n, vector<int> &nums){
/*In the for-loop approach for generating subsets, you must add the current subset to the answer before exploring further.

Your base case

if(index >= n){
    ans.push_back(ds);
    return;
}

only inserts subsets when index == n.

Consider nums = [1,2].

Your recursion produces:

[1,2]
[2]

But it never inserts

[]
[1]

because those calls never reach index == n.

Correct approach

Instead of waiting for index == n, insert the current subset at the beginning of every recursive call.*/
    // if(index >= n){
    //     ans.push_back(ds);
    //     return;
    // }
    ans.push_back(ds);
    //No base case statement is needed as when i == n the for loop overs and return itself
    for(int i = index; i < n; i++){
    for(int i = index; i < n; i++){
        if(i != index && nums[i] == nums[i-1])continue;//if i = index it is the first time we are reaching the duplicate element else it is not the first time and its subset has already been made
        ds.push_back(nums[i]);
        printSubseqSum(i + 1, ds, ans, n, nums);
        ds.pop_back();
    }
    return;
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        printSubseqSum(0, ds, ans, n, nums);
        
        return ans;
    }
};//Approach almost same as combination sum II T.C. = O((2^N)*N), S.C. = O((2^N)*X)
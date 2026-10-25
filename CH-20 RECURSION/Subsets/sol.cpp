/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]*/
class Solution {
public:

    void printAllSubset(int index, vector<int> &ds, vector<vector<int>> &ans, int n, vector<int> &arr){
        if(index >= n){
            ans.push_back(ds);
        return;
        }

        ds.push_back(arr[index]);
        printAllSubset(index + 1, ds, ans, n, arr);

        ds.pop_back();
        printAllSubset(index + 1, ds, ans, n, arr);
        return;
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        printAllSubset(0, ds, ans, n, nums);

        return ans;

    }
};
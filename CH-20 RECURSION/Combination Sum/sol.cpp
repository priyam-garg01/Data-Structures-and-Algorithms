/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40*/
class Solution {
public:

void printAllSubseqSumK(int index,vector<vector<int>> &ans,vector<int> &ds,vector<int> &arr, int n, int k){
        if(index == n){
            if(k == 0){
                ans.push_back(ds);//O(K)
            }
            return;
        }
        
       if(k >= arr[index]){
        ds.push_back(arr[index]);
     printAllSubseqSumK(index, ans, ds, arr, n, k - arr[index]);
        ds.pop_back();
}

        printAllSubseqSumK(index + 1, ans, ds, arr, n, k);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = candidates.size();
        printAllSubseqSumK(0, ans, ds, candidates, n, target);
        
        return ans;
    }
};/*There is no need of sum variable as we can directly subtract the element from our target
T.C. = O((2^t)*k) where t is the number of times a recursive call is made for the worst case{sum made from smallest possible element summation} 
and k is the avg length{worst case} of of ans arr to add all combinations in ans a loop of o(k)
S.C. = O(K*X){where x is the number of possible combinations}*/